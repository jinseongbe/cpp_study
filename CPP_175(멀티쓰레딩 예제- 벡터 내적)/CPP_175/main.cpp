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
        
        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);    // 0ull 표기로 인해 auto가 sum을 longlong으로 인식하게 해줌
        
        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Naive" << endl;    // Race Condition이 발생하여 결과가 잘못나오는 것을 확인 할 수 있음
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
    
    cout << "Lockguard" << endl;    // 너무 단순한 연산이라 lockguard를 사용헌게 오히려 시간이 더 걸리는 현상이 생김
    {                               // Lock이 걸리는 횟수가 너무 빈번한 상황임, 이런경우는 오히려 느려지니 사용 x
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

    cout << "Atomic" << endl;   // atomic 연산이 기본 연산보다 느리기 때문에, 빈번하게 호출 될. 경우 느려지는 상황 발생함
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
    
    cout << "Futrue" << endl;   // 이 경우에는 각 thread가 계산한것들을 마지막에 합쳐주는 방식으로 확실히 빠르다!
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


    // apple에서는 지원하지 않는것으로 보임
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
