#include <iostream>

using namespace std;

// 1. 외부 함수에서 불러다가 사용하는 방법
class B;    // 전방선언(forward declaration)!!!! class A에서 사용하기 위함
            // 코드를 읽을때 좀 불편해서 홍정모씨는 잘 쓰진 않으신다고함
class A
{
private:
    int m_value = 1;
    
    friend void doSomething(A &a);          // friend 함수로 지정해줄 경우 함수가 private 변수에도 접근 가능하다!!
    friend void doSomething2(A &a, B &b);   // 두개의 class에서 이용하려면 둘다 friend로 정의해줘야함
};                                          // 여기서 문제는 B class를 컴파일러가 읽기 전이기 때문에 전방선언해줘야함!


class B
{
private:
    int m_value = 2;
    friend void doSomething2(A &a, B &b);
};

void doSomething(A &a)
{
    cout << "only A" << endl;
    cout << a.m_value << endl;
}

void doSomething2(A &a, B &b)
{
    cout << "A and B" << endl;
    cout << a.m_value << " " << b.m_value << endl;
}


// 2.다른 class에 있는 것을 사용하는 방법

class BB;   // AA 안에서 class BB를 불러오는 함수를 사용하기 떄문에 전방선언이 필수적임!

class AA
{
private:
    int m_value = 1;
    
    // 2-1 다른 class를 전부 가져오는 방법 (A에서 B의 모든 것을 사용 가능)(B->A)
    friend class BB;        // 이 경우는 전방선언을 따로 하지 않아도 됨!

public:
    // 아래는 2-2 사용을 위해 선언해준것임! class AA에서 classBB 안에 있는 것까진 순서상 미리 알수 없기 때문에, 선언과 정의 분리
    void doSomeInA_part(BB &b);
};

class BB
{
private:
    int m_value = 4;
    
    // 2-2 다른 class를 일부만 가져오는 방법 (B에서 A의 함수 하나를 가져다 사용하는 것임)(A->B)
    friend void AA::doSomeInA_part(BB &b);// class를 전부 개방하는것이 부담스러워 일부만 개방하고 싶을때는 이렇게도 가능

public:
    // 2-1에서 가져올 함수
    void doSomeInB(AA &a)
    {
        cout << a.m_value << endl;
    }
};
    
    // 2-2에서 선언해준 AA내부의 함수의 몸체는 밖에 정의해준것임
void AA::doSomeInA_part(BB &b)
{
    cout << b.m_value << endl;
}

    

int main()
{
    A a;
    doSomething(a);
    cout << endl;
    
    AA aa;
    BB bb;
    
    bb.doSomeInB(aa);
    aa.doSomeInA_part(bb);
    
    
    return 0;
}
