#include "AutoPtr.h"
#include "Resource.h"
#include <vector>
#include <string>

using namespace std;

template<class T>
void MySwap(T &a, T &b)
{
//    T tmp = a;
//    a = b;
//    b = tmp;
    
    T tmp{ std::move(a) };
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
//    1.
//    {
//        AutoPtr<Resource> res1(new Resource(10000000));
//
//        cout << res1.m_ptr << endl;
//
////        AutoPtr<Resource> res2 = res1;
//        AutoPtr<Resource> res2 = std::move(res1);   // 내부적으로 복잡한 작동을 하는것이 아니고, 들어가는 값을 R-value로 인식하게 만들어줌!
//                                                    // =(R-value를 return 해줌)
//
//        cout << res1.m_ptr << endl;
//        cout << res2.m_ptr << endl;
//    }
    
//    2.(왜안됨????)
    {
        AutoPtr<Resource> res3(new Resource(3));
        res3->setAll(5);

        AutoPtr<Resource> res4(new Resource(5));
        res4->setAll(5);

        res3->print();
        res4->print();

        MySwap(res3, res4);

        res3->print();
        res4->print();
    }
    
//    3.
//    {
//        vector<string> v;
//        string str = "Hello";
//
//        v.push_back(str);
//
//        cout << str << endl;
//        cout << v[0] << endl;
//
//        v.push_back(std::move(str));
//
//        cout << str << endl;        // str에 있던 "hello"가 move해서 없어져버림!
//                                    // 이것도 std::vector안에 move semantice를 구현해 놓았기 떄문에 사용 가능한 것임! 무조건 되는게 아녀~
//        cout << v[0] << " " << v[1] << endl;
//    }
    
//    4.MySwap에서 전달되는 operator가 다름, debuger로 찍어보슈
    {
        std::string x{ "abc" };
        std::string y{ "de" };
        
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        
        MySwap(x, y);
        
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    }
    
    return 0;
}
