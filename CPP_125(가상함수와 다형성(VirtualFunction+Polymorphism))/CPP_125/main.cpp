#include <iostream>

using namespace std;

class A
{
public:
    virtual void print()        // virtual 함수는 stack처럼 쌓이는 구조가 아니라
    {                           // 랜덤으로 찾아가는 과정이기 때문에 느리다,
        cout << "A" << endl;    // 따라서 많이 쓰이는 함수(for안에 넣는다던지?)애는 사용하지 않는 것이 좋다!
    }
};

class B : public A
{
public:
    virtual void print()        // 사실 A에만 있어도 가상함수를 오버라이딩 하는것을 알수 있지만
    {                           // 디버깅할땡(사람들이 볼때) 이해하기 쉽도록 그냥 다 virtual을 써준다!
        cout << "B" << endl;
    }
};

class C : public B
{
public:
    virtual void print()
    {
        cout << "C" << endl;
    }
};

class D : public C
{
public:
    virtual void print()
    {
        cout << "D" << endl;
    }

//    virtual int print()           // return type이 다르면 컴파일 오류 발생!
//    {                             // A와 다르기 때문에! 맨 위에 부터 상속구조를 보고옴
//        cout << "D" << endl;
//        return 0;
//    }
};



int main()
{
    A a;
    B b;
    C c;
    D d;

    
    B &ref = c;
    ref.print();
    

    return 0;
}
