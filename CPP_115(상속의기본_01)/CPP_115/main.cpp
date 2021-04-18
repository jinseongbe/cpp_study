#include <iostream>

using namespace std;

class Mother
{
private:
    
protected:
    int m_i;

public:
    Mother()    // 1. 상속과정에서 Son class의 생성자가 실행되는 동시에 Mother class의 생성자를 호출하는데 이떄
    : m_i(0)    //    아래와 같이 대입해줘야하는 값이 있으면 오류가 뜨기 때문에 디폴트생성자를 다시 정의해줘야 한다!!
    {}
    
    Mother(const int &i_in)
    : m_i(i_in)
    {
        std::cout << "Mother constructor" << std::endl;
    }
    
    void setValue(const int &i_in)
    {
        m_i = i_in;
    }
    
    int getValue()
    {
        return m_i;
    }
};


class Child : public Mother // derived class 상속을 받았다는 것을 이렇게 표현함
{
private:
    double m_d;
    
public:
    void setValue(const int &i_in, const double &d_in)
    {
        m_i = i_in;     // protected를 사용하면 상속받은 자식함수는 접근가능하게 된다!!
//        Moter::setValue(i_in);    // private를 사용하고 싶다면 이렇게 사용해도 됨!
        m_d = d_in;
    }
    
    void setValue(const double &d_in)   // 성속받은 것과 같은 이름의 함수를 사용하면 자신이 정의한 것으로 정의한다!!
    {
        m_d = d_in;
    }
    
    double getValue()
    {
        return m_d;
    }
};

class Son : public Mother
{
private:
    double m_d;
    
public:
    Son(const int &i_in, const double &d_in)
    : Mother(i_in), m_d(d_in)   // 2. 그냥 마더클래스에 바로 넣어주면 된다! 이 방법이 1번 방법보다 좀더 우아함
//    : m_i(i_in), m_d(d_in)  // 안되는 이유: 생성자(constructor)의 목적은 메모리를 생성할때 초기화 해주세요 라는 뜻인데,
    {                         // 상속받기전에 m_i는 이미 메모리를 할당받아논것이기 때문이다!!
//        Mother::setValue(i_in); // 1번 방법으로 했을때!
//        m_d = d_in;
    }   // 따라서 위와 같이 넣어줘야 한다!
    
    double getValue()
    {
        return m_d;
    }
};



int main()
{
    Mother mother(2048);
//    mother.setValue(1024);
    cout << mother.getValue() << endl << endl;

    Child child;
    child.setValue(1024);
    cout << child.getValue() << endl;
    child.Mother::setValue(2048);
    cout << child.Mother::getValue() << endl << endl;
    
    Son son(1024, 128);
    cout << son.getValue() << endl;
    cout << son.Mother::getValue() << endl << endl;
    
    return 0;
}
