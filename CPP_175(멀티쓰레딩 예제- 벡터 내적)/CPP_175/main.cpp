#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>          // std::inner_product
#include <execution>        // parallel execution

using namespace std;

mutex mtx;

void dotProductNaive(const vector<int> & v0, const vector<int> & v1,
                     const unsigned i_start, const unsigned i_end, unsigned long long & sum)
{
    for (unsigned i = i_start; i < i_end; ++i)
        sum += v0[i] * v1[i];
}

void dotProductLock(const vector<int>& v0, const vector<int>& v1,
                    const unsigned i_start, const unsigned i_end, unsigned long long & sum)
{
//    cout << "Thread start " << endl;
    
    for (unsigned i = i_start; i < i_end; ++i)
    {
        std::scoped_lock lock(mtx);     // c++17
        sum += v0[i] * v1[i];
    }
    
//    cout << "Thread end " << endl;
}

void dotProductAtomic(const vector<int> & v0, const vector<int>& v1,
                      const unsigned i_start, const unsigned i_end, atomic<unsigned long long> & sum)
{
    for (unsigned i = i_start; i < i_end; ++i)
        sum += v0[i] * v1[i];
}

auto dotProductFuture(const vector<int>& v0, const vector<int>& v1,
                      const unsigned i_start, const unsigned i_end)
{
    int sum = 0; // local sum
    for (unsigned i = i_start; i < i_end; ++i)
    {
        sum += v0[i] * v1[i];
    }
    
    return sum;
}

void dotProductNaive_edit(const vector<int>& v0, const vector<int>& v1,
                      const unsigned i_start, const unsigned i_end, vector<unsigned long long>& sum_vec, int t)
{
    int sum_local = 0; // local sum
    for (unsigned i = i_start; i < i_end; ++i)
    {
        sum_local += v0[i] * v1[i];
    }
    
    sum_vec[t] = sum_local;
}


int main()
{
    /*
     v0 = { 1, 2, 4 }
     v1 = { 4, 5, 6 }
     v0_dot_v1 = 1*4 + 2*5 + 3*6;
     */
    
    const long long n_data = 10'000'000;
    const unsigned  n_threads = 8;
    
    // initialize vectors
    std::vector<int> v0, v1;
    v0.reserve(n_data);
    v1.reserve(n_data);
    
    random_device seed;
    mt19937 engine(seed());
    
    uniform_int_distribution<> uniformDist(1, 10);
    
    for (long long i = 0; i < n_data; ++i)
    {
        v0.push_back(uniformDist(engine));
        v1.push_back(uniformDist(engine));
    }
    
    cout << "std::inner_product" << endl;
    {
        const auto sta = chrono::steady_clock::now();
        
        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);    // 0ull ????????? ?????? auto??? sum??? longlong?????? ???????????? ??????
        
        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Naive" << endl;    // Race Condition??? ???????????? ????????? ??????????????? ?????? ?????? ??? ??? ??????
    {
        const auto sta = chrono::steady_clock::now();
        
        unsigned long long sum = 0;
        
        vector<thread> threads;
        threads.resize(n_threads);
        
        const unsigned n_per_thread = n_data / n_threads;   // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
        {
            threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1),
                                     t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        }
        
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }
    
    cout << "Lockguard" << endl;    // ?????? ????????? ???????????? lockguard??? ???????????? ????????? ????????? ??? ????????? ????????? ??????
    {                               // Lock??? ????????? ????????? ?????? ????????? ?????????, ??????????????? ????????? ???????????? ?????? x
        const auto sta = chrono::steady_clock::now();
        
        unsigned long long sum = 0;
        
        vector<thread> threads;
        threads.resize(n_threads);
        
        const unsigned n_per_thread = n_data / n_threads;   // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
        {
            threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
                                     t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        }
        
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Atomic" << endl;   // atomic ????????? ?????? ???????????? ????????? ?????????, ???????????? ?????? ???. ?????? ???????????? ?????? ?????????
    {
        const auto sta = chrono::steady_clock::now();
        
        atomic<unsigned long long> sum = 0;
        
        vector<thread> threads;
        threads.resize(n_threads);
        
        const unsigned n_per_thread = n_data / n_threads;   // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
        {
            threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
                                     t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        }
        
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }
    
    cout << "Futrue" << endl;   // ??? ???????????? ??? thread??? ?????????????????? ???????????? ???????????? ???????????? ????????? ?????????!
    {
        const auto sta = chrono::steady_clock::now();
        
        unsigned long long sum = 0;
        
        vector<std::future<int>> futures;
        futures.resize(n_threads);
        
        const unsigned n_per_thread = n_data / n_threads;   // assumes remainder = 0;
        for (unsigned t = 0; t < n_threads; ++t)
        {
            futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
                                    t * n_per_thread, (t +1) * n_per_thread);
        }
        
        for (unsigned t = 0; t < n_threads; ++t)
            sum += futures[t].get();
        
        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    
    cout << "Threads divide and conque strategy" << endl;
    {
        const auto sta = chrono::steady_clock::now();
        
        unsigned int long long sum = 0;
        
        vector<thread> threads;
        threads.resize(n_threads);
        
        vector<unsigned long long> sum_vec;
        sum_vec.resize(n_threads);
        
        const unsigned n_per_thread = n_data / n_threads;   // assumes remainder = 0
        
        for (unsigned t = 0; t < n_threads; ++t)
        {
            threads[t] = std::thread(dotProductNaive_edit, std::ref(v0), std::ref(v1),
                                     t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum_vec), t);
        }
        
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();
        
        for (unsigned t = 0; t < n_threads; ++t)
        {
            sum += sum_vec[t];
        }
        
        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }


    // apple????????? ???????????? ??????????????? ??????
//    cout << "std::transform_reduce" << endl;
//    {
//        const auto sta = chrono::steady_clock::now();
//
////        const auto sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), v1.begin(), 0ull);
//        const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);
//
//        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
//
//        cout << dur.count() << endl;
//        cout << sum << endl;
//        cout << endl;
//    }
    
    
    return 0;
}

// TODO: use divide and conque strategy for std::thread(+ atomic)
// TODO: use promise
