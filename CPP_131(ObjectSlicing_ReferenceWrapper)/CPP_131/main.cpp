#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
public:
    int m_i = 0;
    
    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1;
    
    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

void doSomething(Base &b)
{
    b.print();
}

void doSomething2(Base b)
{
    b.print();
}

int main()
{
    Derived d;
    // 다형성을 구성하다가 실수 할 수 있는 경우!
    Base &b = d;
    Base c = d;
    
    b.print();
    c.print();
    
    
    // 실수 할 수 있는 경우2 '&'를 빼먹는 경우
    doSomething(d);
    doSomething2(d);
    
    
    // 초보 프로그래머들이 자주 실수하는 경우!
    Base bb;
    Derived dd;
    
    std::vector<Base> my_vec;
    my_vec.push_back(bb);
    my_vec.push_back(dd);   // pushback을 하는 과정에서 슬라이싱이 발생함
    
    for (auto &ele : my_vec)
    {
        ele.print();
    }
    
    // 해결법 1. 포인터를 사용하는경우
    std::vector<Base*> my_vec2;
    my_vec2.push_back(&bb);
    my_vec2.push_back(&dd);   // pushback을 하는 과정에서 슬라이싱이 발생함
    
    for (auto &ele : my_vec2)
    {
        ele->print();
    }
    
    // 해결법 2. reference를 어떻게는 사용하는경우!
    std::vector<std::reference_wrapper<Base>> my_vec3;  // 원래 referenc는 vector에 사용 할 수 없음!
//    std::vector<Base&> my_vec3;                       // 마치 이것 처럼 작동하는 것임
    my_vec3.push_back(bb);
    my_vec3.push_back(dd);   // pushback을 하는 과정에서 슬라이싱이 발생함
    
    for (auto &ele : my_vec3)
    {
        ele.get().print();
    }

    return 0;
}
