#include <iostream>

using namespace std;

class Base
{
protected:
    int m_i;
    
public:
    Base(int value)
    : m_i(value)
    {
    }
    
    void print()
    {
        cout << "I'm base" << endl;
    }
    
    friend std::ostream & operator << (std::ostream & out, const Base &b)
    {
        out << "This is base output" << endl;
        return out;
    }
};

class Derived : public Base
{
public:
    Derived(int value)
    : Base(value)
    {
    }
    
    void print()    // 함수가 오버로딩됨!
    {
        cout << "I'm derived" << endl;
        
        // 오버로딩을 하고 싶지 않을 경우
        Base::print();
        // 주의 만약 자기자신을 호출하지 않겠지라는 생각으로 print()만 쓸경우
        // 무한반복으로 인해 프로그램이 다운 될 수도 있으니 주의할것
    }
    
    friend std::ostream & operator << (std::ostream & out, const Derived &b)
    {
//        out << "This is derived output" << endl;
//        return out;
        
        // 연산자 오버로딩을 하고 싶을 경우 특히 friend를 사용할 경우
        cout << static_cast<Base>(b) << endl;
        return out;
    }


};

int main()
{
    
    Base base(5);
    base.print();
    
    Derived derived(7);
    derived.print();
    
    cout << base;
    cout << derived;
    
    
    
    
    return 0;
}
