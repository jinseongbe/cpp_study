#include <iostream>
#include <string>

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

class Derived1 : public Base
{
public:
    int m_j = 1024;
    
    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

class Derived2 : public Base
{
public:
    string m_name = "Dr. Tow";
    
    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};


int main()
{
    Derived1 d1;
    
    // d1을 다시 access 할 수 없는 경우 사용하는것임!
    Base * base = &d1;
    
    auto *base_to_d1 = dynamic_cast<Derived1*>(base);
    
    cout << base_to_d1->m_j << endl;
    
    base_to_d1 -> m_j = 2;
    
    cout << d1.m_j << endl;
    cout << endl;
    
    // 주의해야 할 점
    auto *base_to_d2 = dynamic_cast<Derived2*>(base);
    if (base_to_d2 != nullptr)
        base_to_d1 -> print();
    else
        cout << "Failed" << endl;
    cout << endl;
    
    // static_cast
    auto *base_to_d3 = static_cast<Derived1*>(base);
    base_to_d3 -> print();
    
    auto *base_to_d4 = static_cast<Derived2*>(base);    // static_cast 왠만하면 다 해주려고 함, 장점일수도 단점일수도 있음!
    base_to_d4 -> print();                              // 무조건 밀어붙인다고 생각하면 됨
    cout << endl;
    
    
    return 0;
}
