#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"


using namespace std;

// RAII : resource acquisition is initialization
//        new(생성)해준곳에서 delete(제거)해줘야 한다라는 패러다임

void doSomething()
{
    try
    {
//        Resource *res = new Resource;   // dull pointer : 수동으로 생성과 삭제를 해줘야 하는 포인터를 지칭하는 말
        
        AutoPtr<Resource> res2(new Resource); // smart pointer
        
        // work with res
        if (true)
        {
            throw -1;
//            delete res;
            return; // early return
        }
        
//        delete res;
    }
    catch (...)
    {
        std::cerr << "error occurs" << std::endl;
    }
    return;
}


int main()
{
    // 1
    doSomething();
    
    
    // 2
    // AutoPtr의 한계점
    {
        AutoPtr<Resource> res1(new Resource);
        AutoPtr<Resource> res2;
        
        cout << std::boolalpha;
        
        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
        
        res2 = res1; // 해결책 = move semantics (move) : 함수내부 확인해볼것
        
        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    }   // resource는 생성이 한번만 되는데 두번 delete되는 현상이 발생함 - runtime Error 발생함!!!!
    
    // ()가 어떻게 쓰이는지에 대한 semantics의 의미
    // value semantics (copy semantics)
    // reference semantics (pointer)
    // move semantics (move)
    

    return 0;
}
