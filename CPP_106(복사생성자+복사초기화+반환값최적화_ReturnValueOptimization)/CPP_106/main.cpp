#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
    
public:
    Fraction(int num = 0, int den = 1)
    : m_numerator(num), m_denominator(den)
    {
        assert(den != 0);
    }
    
    Fraction(const Fraction &fraction)  // copy constructor :  추가적으로 복사를 막고싶을때! -> copyconstructor를 private로 바꾼다(옮긴다!)
    : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "Copy constructor called" << endl;
    }
    
    friend std::ostream & operator << (std::ostream &out, const Fraction &f)
    {
        out << f.m_numerator << "/" << f.m_denominator;
        return out;
    }
};

Fraction doSomething()
{
    Fraction temp(1, 2);
    cout << &temp << endl;
    return temp;
}


int main()
{
    Fraction frac(3, 5);
    
    Fraction fr_copy(frac);
    Fraction fr_copy2 = frac;       // 등호로도 copy constructor가 호출된다!
    cout << frac << "\t" << fr_copy << "\t" << fr_copy2 << endl;
    
    Fraction fr_copy3(Fraction(3, 20));     // 이 경우도 복사가 가능하다! 그러나 copy constructor을 호출하지 않고
                                            // 컴파일러가 알아서 fr_copy3(3, 20)으로 만들어서 사용한다! 생략해버림
    cout << endl;
    
    
    // 컴파일러의 최적화 기능으로 생성자를 거치지 않고 바로 class가 생성됨(값이 입력됨)
    Fraction result = doSomething();
    cout << result << endl;
    cout << &result << endl;    // 함수 내부에 있는 class와 주소가 같다!!
    
    
    
    
    return 0;
}
