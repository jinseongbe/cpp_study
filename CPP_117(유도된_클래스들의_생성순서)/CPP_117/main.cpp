#include <iostream>

using namespace std;

class Mother
{
public:
    int m_i;
    
    Mother()
    : m_i(1)
    {
        cout << "Mother constructor" << endl;
    }
};

class Child : public Mother
{
public:
    double m_d;
    
    Child()
    : Mother(), m_d(1.0)        // Mother()가 생략되어있는것임!
    {                           // Mother(1024)처럼 Mother class에 생성자를 만들어주면 대입하면서 초기화가능하다!
        cout << "Child constructor" << endl;
    }
};


class A
{
public:
    A()
    {
        cout << "A Constructor" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "B Constructor" << endl;
    }
};

class C : public B
{
public:
    C()
    {
        cout << "C Constructor" << endl;
    }
};



int main()
{
    Child child;
    
    C c;
    
    return 0;
}
