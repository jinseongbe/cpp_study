#include <iostream>

using namespace std;

class Something1
{
public:
    class _init
    {
    public:
        _init()
        {
            s_value = 1234;
        }
    };

private:
    static int s_value;
    int m_value;
    static _init s_initializer;
    
public:
    Something1()
//    : m_value(47), s_value(100) //static 맴버변수는 생성자에서 정의할수없다!
    {
        m_value = 46;
    }
    
    static int getValue()
    {
        return s_value;
//        return this->m_value;     // static member function은 this를 사용 할 수 없다!!
//        return m_value;           // 이 말은 단순히 this 문법을 못쓰는게 아니라, this로 접근해야 하는
    }                               // 모든게 안된다는 것임(즉, static mmember 변수인 s_value는 사용가능하나
                                    // 그냥 변수인 m_value는 사용이 불가능함!)
    int temp()
    {
        return this->s_value + this->m_value;
    }
};

int Something1::s_value = 1024;
Something1::_init Something1::s_initializer;    // 생성자에서 정의가 안되기 때문에 다른 방식으로 정의하는 법으로
                                                // enum class를 사용하여 _init을 정의하면서 변수를 호출하고
                                                // 그것을 다시 s_value에 넣는 방식으로 우회하여 할 수는 있다!
                                                // 그러나 자주 쓸일은 없지 않을까 싶다!


int main()
{
    cout << Something1::getValue() << endl;     // static을 사용할경우 class를 부여하지 않고
                                                // 내부에 직접 접근 할 수 있다!!
    Something1 s1, s2;
    cout << s1.getValue() << endl;              // 이렇게 해야하는것이 기본 이었음!
    cout << endl << endl;
    
    
    //    int (Something1::*fptr1)() = &s1.temp();      // 맴버 함수의 주소는 포인터로 따로 저장할수가 없음!
                                                        // 맴버 함수는 주소가 하나임! 즉s1,s2의 함수의 주소는 동일
                                                        // class에서는 함수를 재활용하는 것을 생각하면 됨
    int (Something1::*fptr1)() = &Something1::temp;     // 따라서 맴버함수의 본연의 주소를 넣어주는 것은 가능
    
    cout << (s2.*fptr1)() << endl;               // 멤버함수를 포인터로 불러서 사용하는 방법은 이렇다!!
    cout << endl << endl;                        // 따라서 s1인지 s2인지 명시해줘야함!
    
    
    
//    int (Something1::*fptr2)() = &Something1::getValue; // 정적멤버함수같은 경우는 이럴경우 에러남
    int (*fptr2)() = &Something1::getValue;               // 정적멤버함수는 어차피 하나로 정해진거니까
                                                          // 다음과 같이 사용해야한다!
    // 맴버함수의 주소는 특정 인스턴스와 묶여 있지 않고, 정적맴버함수는 다른식으로 사용해야한다!
    
    
    
    
    
    return 0;
}
