#include <iostream>
#include <future>
#include <thread>

using namespace std;

int main()
{
    // multi-threading
    {
        int result;
        std::thread t([&] {result = 1 + 2; });
        t.join();
        cout << result << endl;
    }
    
    
    // task-based parallelism
    {
        // std::future<int> fut = ...  미래에 받아오겠다는 정도의 의미
        auto fut = std::async([] { return 1 + 2; });    // 일반적으로 thread보다 async를 사용하는 것을 더 선호함
        cout << fut.get() << endl;                      // 중요한 차이 : 위에 것은 thread애 잡중하는것에 비해, async는 작업에 초점을 맞춤
    }                                                   // fut.get = 값을 return 받을때 까지 기다렸다가 실행된다.
    
    
    // future and promise
    {
        std::promise<int> prom;
        auto fut = prom.get_future();
        
        auto t = std::thread([](std::promise<int>&& prom)
        {
            prom.set_value(1 + 2);
        }, std::move(prom));
//        t.join();     // 조인을 여기에 두어도 문제는 없음!
        cout << fut.get() << endl;
        t.join();
    }
    
    
    // thread와 async의 중요한 차이중 하나 : 소멸자가 끝나기를 알아서 대기해줌(join이 없어도 문제가 생기지 않음)
    {
        auto f1 = std::async([] {
            cout << "async1 start" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "async1 end" << endl;
        });
        
        
        auto f2 = std::async([] {
            cout << "async2 start" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "async2 end" << endl;
        });
        
        std::cout << "Main function" << endl;
    }

    return 0;
}




