#include <iostream>

using namespace std;

class Base
{
public:
    int m_public;
    
protected:
    int m_protected;
    
private:
    int m_private;
};

class Derived : public Base
{
public:
    Derived()
    {
        m_public = 123;
        m_protected = 1234;
        // m_private = 12345;        // 안됨!
        
    }
};

class GrandChild : public Derived
{
public:
    GrandChild()
    {   // Derived가 private Base로 상속받은경우 3가지 모두 작동하지 않음!
        m_public = 123;
        m_protected = 1234;
//        m_private = 12345; 안됨
    }
    
};


int main()
{
    Base base;
    
    base.m_public = 123;
//    base.m_private = 1234;        // 안됨!
//    base.m_protected =12345;      // 안됨!

    Derived derived;
    
//    1. public Base로 상속받았을떄
    derived.m_public = 1234;
//    derived.m_private = 1235345;  // 안됨
//    derived.m_protected = 12345;  // 안됨
    
//    2. protected Base 상속받았을때
//        derived.m_public = 1234;      // 안됨
//        derived.m_private = 1235345;  // 안됨
//        derived.m_protected = 12345;  // 안됨

    return 0;
}
