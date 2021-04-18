#include <iostream>

using namespace std;

class Simple
{
private:
    int m_id;
    
public:
    Simple(int id)
    {
        this->setID(id); // == setID(id)
        // 'this->'가 생략되어 있는것임! 그래서 같은 class 여러번 사용하더라도 구분할수있는거임!
        // 즉 class의 함수들은 매번 메모리를 할당받아 만드는 것이 아니라, 재활용하는것임!
        cout << this << endl;   // this는 현재 주소를 나타냄
    }
    
    void    setID(int id) { m_id = id; }
    int     getID() { return m_id; }
 
};

class Calc
{
private:
    int m_value;
    
public:
    Calc(int int_value)
    : m_value(int_value)
    {}
    
    /*
    void add(int value) { m_value += value; } // cal1은 다음과 같이 작성했을때
    void sub(int value) { m_value -= value; }
    void mult(int value) { m_value *= value; }
    */
    Calc &add(int value) { m_value += value; return *this; }    // cal2는 다음과 같이 작성했을때(얀쇄호출)
    Calc &sub(int value) { m_value -= value; return *this; }    // cal1도 사용가능함!
    Calc &mult(int value) { m_value *= value; return *this; }
    
    void print()
    {
        cout << m_value << endl;
    }
};



int main()
{
    Simple s1(1), s2(2);
    s1.setID(2);
    s2.setID(4);
    
    cout << &s1 << "\t" << &s2 << endl;
    
    
    // 연쇄 호출
    Calc cal1(10);
    cal1.add(10);
    cal1.sub(1);
    cal1.mult(2);
    
    cal1.print();
    
    Calc cal2(10);
    cal2.add(10).sub(1).mult(2).print();
    
    Calc(10).add(10).sub(1).mult(2).print();    // 이렇게도 사용 가능하다
    
    /* 위는 아래와 같이 작동하는 것이 간소화된것임!, 쓸모가 있는지는 의문임(cpp입장에서는 번거롭다고 느껴진다는 사견)
    Calc cal(10);
    Calc &temp1 = cal.add(10);
    Calc &temp2 = temp1.sub(1);
    Calc &temp3 = temp2.mult(2);
    temp3.print();
    */
    
    
    return 0;
}
