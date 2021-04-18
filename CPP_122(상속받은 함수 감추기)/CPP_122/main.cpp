#include <iostream>

using namespace std;

class Base
{
protected:
    int m_i;
    
public:
    Base(int value)
    : m_i(value)
    {}
    
    void print()
    {
        cout << "I'm base" << endl;
    }
    
    void print2()
    {
        cout << "I'm base" << endl;
    }
};

class Derived : public Base
{
private:
    double m_d;
    
public:
    Derived(int value)
    : Base(value)
    {}
    
    using Base::m_i;        // public 안에 using으로 넣어줄경우 상속받은 클래스에서 사용 가능!

    // 상속받은 클래스에서 사용 못하게 하는 방법
    // 1. private 안에 using을 사용한다
private:
    using Base::print; // do not add (), cause this is name
    
    // 2. delete 해버린다
private:
    void print2() = delete;
    
};

int main()
{
    Derived derived(7);
    
    derived.m_i = 123;
    
    cout << derived.m_i << endl;
    
    derived.print(); //private using으로 넣을 경우 사용 할 수 없음!
    derived.print2();
    return 0;
}
