// 여러개의 thread가 하나의 메모리 공간을 사용하다 보면 오류가 발생 할 수 있는데, 이러한 문제를 Race Condition(경합조건)이라고 한다.
// atomic과 scoped_lock을 통해서 하결 가능함

#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>
 
using namespace std;

mutex mtx;


int main()
{
     int shared_memory_num(0);
    
    // 해결법 1. atomic
//    atomic<int> shared_memory_num(0);
    
    auto count_func = [&]() {
        for (int i = 0; i < 1000; ++i)
        {
            this_thread::sleep_for(chrono::milliseconds(1));    // 이것을 빼면, 연산속도가 너무 빨라서 Race Condition이 발생하지 않지만, 가능성은 존재하는것임
                                                                // 오류가 안생긴다고 오해하진 말자! Race Condition은 예방해야한다!
            
            // 해결법 1. atomic
//            shared_memory_num++;    // atomic사용시 atomic증감연산자가 오버로딩 되어 작동함!
                                    // 이렇게 사용시 원래 증감연산자보다는 조금씩 느린것이 단점!(퍼포먼스 저하)
                                    // 따라서 꼭 필요한 곳에서만 사용하는것이 좋다
//            shared_memory_num.fetch_add(1);   // 이렇게도 사용 가능!
            
            
            // 해결법 2-1. mutex 사용, 이 부분에서는 unlock이 실행이 안되는(예외처리와 같은) 문제가 발생할 가능성이 있음!
//            mtx.lock();
//            shared_memory_num++;
//            mtx.unlock();
            
            
            // 해결법 2-2. (2-1)의 문제점을 보완하기 위해, std::lock_guard사용
//            std::lock_guard<mutex> lock(mtx);       // 이럴경우에는 lock이라는 변수가 이 스코프안에서 선언된것이기 때문에, 직접 unlock해줄 필요가 없음
//            shared_memory_num++;                    // 대부분의 경우 이렇게 사용하는 것을 권장함
            
            
            // 해결법 3. c++ 17 이상, std::scoped_lock 사용, 업그레이드된 진보된 lock
            std::scoped_lock<mutex> lock(mtx);
            shared_memory_num++;
            // 이렇게 사용하는 것을 권장하고 있음!
        }
    };
    
    thread t1 = thread(count_func);
    thread t2 = thread(count_func);
    
    t1.join();
    t2.join();
    
    cout << "After" << endl;
    cout << shared_memory_num << endl;
    
    
    
    
    return 0;
}
