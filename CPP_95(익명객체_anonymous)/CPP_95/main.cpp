#include <iostream>

using namespace std;

class A
{
private:
    int m_value = 10;
    
public:
    A()
    {
        cout << "Constructor" << endl;
    }
    
    void print()
    {
        cout << m_value << endl;
    }
    
    ~A()
    {
        cout << "distructor" << endl;
    }
};

class Cents
{
private:
    int m_cents;
    
public:
    Cents(int cents)
    {
        m_cents = cents;
    }
    
    int getCents() const
    {
        return m_cents;
    }
    
};

Cents add(const Cents &c1, const Cents &c2)
{
    return Cents( c1.getCents() + c2.getCents() );
}



int main()
{
    A a;
    a.print();
    cout << endl;
    
    // 익명개체: 이렇게 하면 생성했다 바로 지우는것이기 때문에, 재사용되는 것이 아니다!
    A().print();
    cout << endl;
    A().print();
    cout << endl;
    
    
    
    // 더 복잡한 용법
    cout << add(Cents(6), Cents(8)).getCents() << endl;
    cout << endl;
    
    return 0;
}
