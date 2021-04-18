// 포인터가 가리키고 있는 데이터의 소유권이 한곳에만 속할 경우에 사용하는 스마트포인터(unique_ptr)

#include <iostream>
#include <memory>
#include "Resource.h"

using namespace std;

auto doSomething()
{
    // 1.
//    auto res1 = str::make_unique<Resource>(5);
//    return res1;

    // 2.
    return std::unique_ptr<Resource>(new Resource(5));

    // 3.
    // return std::make_unique<Resource>(5);
}

void doSomething2(std::unique_ptr<Resource> & res)
{
    res->setAll(10);
}

auto doSomething3(std::unique_ptr<Resource> res)
{
    res->setAll(17);
    
    return res;
}


void doSomething4(Resource *res)
{
    res->setAll(15);
}

int main()
{
    {
        // 1.
//        Resource *res = new Resource(10000000);
        // early return or throw
//        delete res;


        // 2.unique_ptr
        std::unique_ptr<Resource> res(new Resource(10000000));
        // 알아서 delete해줌
    }
    
    cout << endl << endl;
    
    {
        std::unique_ptr<int> upi(new int);      // 기본형에도 사용 가능
        
        std::unique_ptr<Resource> res1(new Resource(5));
        
        // 조금더 권장하는 방법(아래)
        auto res3 = std::make_unique<Resource>(5);
        
        // 함수로 받는 방법
        auto res4 = doSomething();
        
        // ptr을 넣어서 초기화 할 수 도 있음
        auto *ptr = new Resource(5);
        std::unique_ptr<Resource> res2(ptr);

        // 조금더 알아보자!
        res1->setAll(5);
        res1->print();
        
        // 초기화를 안해준것
        std::unique_ptr<Resource> res5;
        
        std::cout << std::boolalpha;
        std::cout << static_cast<bool>(res1) << std::endl;
        std::cout << static_cast<bool>(res5) << std::endl;
        
        // unique pointer의 특성! 복사가 되지 않는다!!
        // res5 = res1 // 작동하지 않음(copy sememtics를 사용 할 수 없음)
        res5 = std::move(res1);
        
        std::cout << std::boolalpha;
        std::cout << static_cast<bool>(res1) << std::endl;
        std::cout << static_cast<bool>(res5) << std::endl;

        if (res1 != nullptr) res1->print();
        if (res2 != nullptr) res5->print(); // (*res5).print()
    }

    cout << endl << endl;
    
    {
        auto res11 = std::make_unique<Resource>(5);
        res11->setAll(1);
        res11->print();
        
        // 1.
        doSomething2(res11);
        res11->print();
        
        // 2.
        res11 = doSomething3(std::move(res11));       // 이렇게 할 경우에는 res11이 null 값이 되어버림!
        res11->print();                               // 살리고 싶으면 다시 소유권을 받으면됨 doSomething2에서 return에서 받아오기
                                                      // 그렇지만 그냥 c++에서는 L-Value를 쓰는게 좋을듯? 위의 방법은 약간 파이썬스타일
        // 3.
        doSomething4(res11.get());              // 유니크포인터가 가지고있는 get함수를 이용하는것, 내부의 Resource의 포인터를 가져오는것
        
        res11->print();
    }
    
    cout << endl << endl;
    
    // 하면 안되는것!!!!!!!!!
    {
        Resource *res = new Resource;
        std::unique_ptr<Resource> res111(res);
        std::unique_ptr<Resource> res222(res);
        // 문제점 1 : unique_ptr은 유일해야 하는데 *res 포인터에 대한 소유권을 두군데에 줘버림!
        //        : 두번 지우려는 문제가 생김!
        
        delete res;
        // 문제점 2 : unique Pointer는 알아서 지워지는데 습관처럼 또 지우려고 하는 문제! 두번지우는 문제발생함!주의할것!
        
    }
    return 0;
}
