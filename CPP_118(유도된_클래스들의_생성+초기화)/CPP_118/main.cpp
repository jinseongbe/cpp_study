#include <iostream>

using namespace std;

class Mother
{
private:
    int m_i;
    
public:
    Mother(const int &i_in = 0)
    : m_i(i_in)
    {
        cout << "Mother constructor" << endl;
    }
};

class Child : Mother
{
public:
    double m_d;
    
    Child()
    : m_d(1.0f), Mother(1024)
    {
        cout << "Child constructor " << endl;
    }
};

class A
{
public:
    A(int a)
    {
        cout << "A : " << a << endl;
    }
    
    ~A()
    {
        cout << "Destruct A" << endl;
    }
};

class B : public A
{
public:
    B(int a, double b)
    : A(a)
    {
        cout << "B : " << b << endl;
    }
    
    ~B()
    {
        cout << "Destruct B" << endl;
    }

};

class C : public B
{
public:
    C(int a, double b, char c)
    : B(a, b)
    {
        cout << "C : " << c << endl;
    }
    
    ~C()
    {
        cout << "Destruct C" << endl;
    }
};


int main()
{
    Child c1;
    
    cout << sizeof(Mother) << endl;
    cout << sizeof(Child) << endl;
    cout << endl;
    
    C c(1024, 3.14, 'a');
    
    return 0;
}
