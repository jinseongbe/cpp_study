#include <iostream>

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
    
    Fraction(const Fraction &frac)
    : m_numerator(frac.m_numerator), m_denominator(frac.m_denominator)
    {
        cout << "Copy constructor called" << endl;
    }
    
    friend std::ostream &operator << (std::ostream &out, const Fraction &f)
    {
        out << f.m_numerator << "/" << f.m_denominator;
        return out;
    }
};

void doSomething(Fraction frac)
{
    cout << frac << endl;
}

class Fraction2
{
private:
    int m_numerator;
    int m_denominator;
    
public:
    Fraction2(char) = delete;       // 업데이트 되면서 이전버전에서 사용을 못하도록 하기 위해 사용되는 편임
    
    explicit Fraction2(int num = 0, int den = 1)        // explicit 더 엄격한 강제 제한이 생김
    : m_numerator(num), m_denominator(den)
    {
        assert(den != 0);
    }
    
    Fraction2(const Fraction2 &frac)           // explicit 더 엄격한 강제 제한이 생김
    : m_numerator(frac.m_numerator), m_denominator(frac.m_denominator)
    {
        cout << "Copy constructor called" << endl;
    }
    
    friend std::ostream &operator << (std::ostream &out, const Fraction2 &f)
    {
        out << f.m_numerator << "/" << f.m_denominator;
        return out;
    }
};

void doSomething2(Fraction2 frac)
{
    cout << frac << endl;
}



int main()
{
    Fraction frac(7);
    
    doSomething(frac);
    doSomething(Fraction(7));
    doSomething(7);
    cout << endl;
    
    // explicit 사용
    Fraction2 frac2(8);
//    doSomething2(7);      // explicit 사용으로 위와는 다르게 정확히 넣어줘야 사용가능하다!
    doSomething2(frac2);
    doSomething2(Fraction2(8));
    
    
    // delete 사용
    Fraction2 frac3('c');   // delete 사용으로 오류 발생함!
    
    return 0;
}
