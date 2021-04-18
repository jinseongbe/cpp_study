#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

template<typename T>
class A
{
public:
    // 생성자를 사용하는경우!
//    A(const T& input)
//    {}
    
    void doSomething()
    {
        cout << typeid(T).name() << endl;
    }
    
    void test()
    {}
};

// class specialize, 실제로는 새로운 클래스를 만드는 양과 비슷(결국은 다른 클래스라고 봐도 무방하다)
template<>
class  A<char>
{
public:
    // 생성자를 사용하는경우!
//    A(const char & temp)
//    {}
    
    void doSomething()
    {
        cout << "Char type specialization" << endl;
    }
};

int main()
{
    A<int>      a_int;
    A<double>   a_double;
    A<char>     a_char;

    // 생성자를 사용하는경우! (c++ 17 이상에서 가능!)
//    A    a_int2(1);
//    A    a_double2(3.14);
//    A    a_char2('a');
    
    // a_char.test(); // 얘는 상속과 다르기때문에 사용 할 수 없음! 헷갈리지 말것!
    
    a_int.doSomething();
    a_double.doSomething();
    a_char.doSomething();
    
    cout << endl;
    
    // 좀 더 실용적인 예제!
    
    // Define a Storage8 for integers
    Storage8<int> intStorage;
    
    for (int count = 0; count < 8; ++count)
    {
        intStorage.set(count, count);
    }
    
    for (int count = 0; count < 8; ++count)
    {
        std::cout << intStorage.get(count) << '\n';
    }
    
    cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>);
    cout << endl;
    
    
    // Define a Storage8 for bool, bool 타입의 클래스를 스페셜라이즈 함으로써 용량을 1바이트에 저장 할 수 있도록 만들었다!
    Storage8<bool> boolStorage;
    for (int count = 0; count < 8; ++count)
    {
        boolStorage.set(count, count);
    }
    
    for (int count = 0; count < 8; ++count)
    {
        std::cout << boolStorage.get(count) << '\n';
    }
    
    cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl;
    
    
    
    
    return 0;
}
