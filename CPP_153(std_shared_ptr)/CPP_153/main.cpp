// unique pointer와 달리 소유권을 여러곳에서 공유 할 수 있는ㄴ shared_ptr
// 여러 군데에서 사용하다가 마지막으로 사용되는 포인터에서 사용이 끝나면 소멸자를 실행한다!
#include <iostream>
#include "Resource.h"

using namespace std;

void doSomething(std::unique_ptr<Resource> res)
{
    
}

int main()
{
    
    Resource *res = new Resource(3);
    res->setAll(1);
    {
        std::shared_ptr<Resource> ptr1(res);
        
        //auto ptr1 = std::make_shared<Resource>(3);
        //ptr1->setAll(1);
        
        ptr1->print();
        
        {
            std::shared_ptr<Resource> ptr2(ptr1);       // shared_ptr은 자신이 몇번 복사되는지 횟수를 세는 기능이 내부적으로 구현되어 있다.!
            
            // 문제가 될 수 있는 상황 : ptr3가 ptr1을 거치지 않고 res로 생성되게 되면, ptr1입장에서는 자신이 shared된지를 모르기 때문에 문제 발생함!
//            std::shared_ptr<Resource> ptr3(res);


            ptr2->setAll(3);
            ptr2->print();
            
            std::cout << "Going out of the block" << std::endl;
        }
        
        ptr1->print();
        
        std::cout << "Going out of the outer block" << std::endl;
    }
    
    // #################################################
    // 사실 위의 방법 보다는 직접적으로 선언하는 아래 방법을 주로 사용함!
    // #################################################
    
    auto ptr11 = std::make_shared<Resource>(3);
    ptr11->setAll(1);
    
    ptr11->print();
    
    {
        std::shared_ptr<Resource> ptr2(ptr11);       // shared_ptr은 자신이 몇번 복사되는지 횟수를 세는 기능이 내부적으로 구현되어 있다.!
        
        auto ptr22 = ptr11;

        ptr22->setAll(3);
        ptr22->print();
        
        std::cout << "Going out of the block" << std::endl;
    }
    
    ptr11->print();
    
    std::cout << "Going out of the outer block" << std::endl;

    
    
    // ####################
    // 추가적으로 주의해야 할 상황
    // ####################
    
    // 유니크 포인터로 받는 상황에서 아래와같이 new를 사용하면서 넣어주는것은 위험함!
//    doSomething(std::unique_ptr<Resource>(new Resource(100000000)));
    // 아래와 같이 make_unique_ptr을 사용하여 완전히 만든뒤 넣어주는것이 좋다! 주의하자!
    doSomething(std::make_unique<Resource>(100000000));
    
    return 0;
}
