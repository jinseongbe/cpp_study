#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents;}

    int getCents() const { return m_cents; }
    int &getCents() { return m_cents; }

};

void add(const Cents &c1, const Cents &c2, Cents &c_out)
{
    c_out.getCents() = c1.getCents() + c2.getCents();
}

class Cents2
{
private:
    int m_cents;
    
public:
    Cents2(int cents = 0) { m_cents = cents;}
    
    int getCents() const { return m_cents; }
    int &getCents() { return m_cents; }
    
    friend Cents2 operator + (const Cents2 &c1, const Cents2 &c2);
    
    // member로 넣을경우 한개는 this로 받도록 바꿔서 변수를 줄여준다!!(왼쪽에 있는 변수를 대체해줌!)
    Cents2 operator - (const Cents2 &c2)
    {
        return Cents2(m_cents - c2.m_cents);
    }
    // '=', '[..]', '()', '->' 등은 member fuction으로만(위의경우) 연산자 오버로딩이 가능하다!
};

Cents2 operator + (const Cents2 &c1, const Cents2 &c2)
{
    return Cents2(c1.m_cents + c2.m_cents); // friend로 넣어주면 getCents를 사용하여 부를필요없음
}

//friend로 class안에 넣어주지 않을 경우 이렇게 써야한다!
//Cents2 operator + (const Cents2 &c1, const Cents2 &c2)
//{
//    return Cents2(c1.getCents() + c2.getCents());
//}


int main()
{
    Cents cents1(6);
    Cents cents2(8);
    
    Cents sum;
    add(cents1, cents2, sum);   // 과거의 코딩 방식, 출력값을 파라미터로 받는 방식 - 최근에는 return 타입으로 받는 경향임
    
    cout << sum.getCents() << endl;
    cout << endl;
    
    // 연산자 오버로딩
    Cents2 cents11(6);
    Cents2 cents22(8);

    cout << (cents11 + cents22 + Cents2(6)).getCents() << endl;
    cout << endl;
    cout << (cents11 + cents22 + Cents2(10)).getCents() << endl;
    cout << endl;
    cout << (cents11 - cents22 - Cents2(10)).getCents() << endl;
    
    
    // 주의점!!
    // '?:(조건연산자)', '::(스코프)', 'sizeof', '.(멤버설렉션)', '.*(멤버포인터설렉션)' 등은 오버로딩인 되지 않는다!!
    // 또한 연산자 우선순의는 기존에 있는 우선순위가 적용되기 때문에 직관적(수학적)으로 통하는 경우를 제외하고는 웬만하면 사용하지 않는다!!
    // '^'은 우선수위가 낮으니까 오버로딩 안하는게 좋음..
    
    
    return 0;
}
