#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx; // mutual exclusion

int main()
{
    
    const int num_pro = std::thread::hardware_concurrency();
    cout << num_pro << endl;    // logical core 개수 : 일반적으로 물리적코어에 2배
    
    cout << std::this_thread::get_id() << endl;             // main 함수가 실행되고 있는 thread의 주소(ID)
    
    // 1.
//    std::thread t1 = std::thread([]() {
//        cout << std::this_thread::get_id() << endl;
//        while(true){ }});
//
//    std::thread t2 = std::thread([]() {
//        cout << std::this_thread::get_id() << endl;
//        while(true){ }});
//
//    std::thread t3 = std::thread([]() {
//        cout << std::this_thread::get_id() << endl;
//        while(true){ }});
//
//    std::thread t4 = std::thread([]() {
//        cout << std::this_thread::get_id() << endl;
//        while(true){ }});
//
//    t1.join();  // thread t1이 끝날때까지 기다려 주는 역할
//    t2.join();
//    t3.join();
//    t4.join();
    
    // 2.
//    vector<std::thread> my_threads;
//    my_threads.resize(num_pro);
//
//    for (auto & e : my_threads)
//    {
//        e = std::thread([]() {
//            cout << std::this_thread::get_id() << endl;
//            while(true) {}});
//    }
//
//    for (auto & e : my_threads)
//    {
//        e.join();
//    }
    
    
    // 3. 출력이 순서대로 나오게 하기 위함 (mutex, mutual exclusion 사용)
    auto work_func = [](const string & name)
    {
        for (int i = 0; i < 5; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            
            mtx.lock();
            cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
            mtx.unlock();   // unlock을 하지 않으면 오류남!! 주의
        }
    };
    
    // multithread 사용 전
//    work_func("jack jack");
//    work_func("Dash");
    
    // multithread 사용 후
    std::thread tt1 = std::thread(work_func, "JackJack");
    std::thread tt2 = std::thread(work_func, "Dash");
    
    tt1.join();
    tt2.join();
    return 0;
}
