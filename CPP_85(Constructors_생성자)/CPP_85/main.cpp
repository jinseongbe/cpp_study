#include <iostream>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
    
public:
//  Fraction() {} 이 default로 있어서 생성자를 만들어 주지 않으면 기본적으로 이렇게 되어있음!(기본생성자)
    Fraction()      // construct(생성자): class와 이름이 동일하면 자동으로 생성자 역할이됨
    {               //                  선언이 됨과 동시에 실행되는 것임!
        m_numerator = 0;
        m_denominator = 1;
    }
    
    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};

class Fraction2
{
private:
    int m_numerator;
    int m_denominator;
    
public:
    Fraction2(const int &num_in, const int &den_in = 1) // 함수처럼 default 값도 설정 가능!!
    {
        m_numerator = num_in;
        m_denominator = den_in;
    }
    
    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};

class Second
{
public:
    Second()
    {
        cout << "class Second constructor()" << endl;
    }
};

class First
{
private:
    Second sec;     // 맴버를 먼저 초기화 해줘야 하기때문에 Second가 먼저 실행됨!
    
public:
    First()
    {
        cout << "class First constructor()" << endl;
    }
};



int main()
{
    Fraction frac;          // 주의사항! construct에 매개변수가 없으면 '()'을 쓰면 안됨 ex) Fraction frac() = (x)
    frac.print();           // 함수와 햇갈리기 때문! 따라서 외워야함! 즉 파라미터를 넣어주지 않으면 그냥 ()뺴라!!
    
    Fraction2 frac2(1, 4);  // 주의사항! construct에 매개변수가 있으면 값을 '()'필요!
    frac2.print();
    
    
    // 두개의 차이!
    Fraction2 frac3{1, 3};  // public일경우 값을 바꾸는 이니셜라이제이션이고, private인경우는 생성자가 없을때는 오류발생
                            // 생성자가 있을때는 아래 식과 같이 작동한다!
    Fraction2 frac4(1, 3);  // 차이점 : 위의 frac3에는 자료형변환을 허용하지 않는다!
                            // 즉 Fraction2 frac3{1.0, 3}은 더블형을 넣어서 오류 발생함!
                            // 그러나 Fraction2 frac3(1.0, 3)은 워닝은 뜨지만 실행은 가능
                            // 그래서 요즘에는 {}로 표기하는것이 더 엄격하다고 하여 좋게 평가되고 있다.
    
    // class 안에 class가 있는 경우
    First fir;              // 실행순서는 second가 먼저 실행됨!
    
    return 0;
}
