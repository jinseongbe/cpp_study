#include <iostream>

using namespace std;

// function try 문법 (전체를 try로 사용) : 근데 잘 안쓰인다고 함
void doSomething()
try
{
    throw - 1;
}
catch (...)
{
    cout << "Catch in doSomething()" << endl;
}


class A
{
private:
    int m_x;
    
public:
    A(int x) : m_x(x)
    {
        if (x <= 0)
        {
            if (x <= 0)
                throw 1;
        }
    }
};

class B : public A
{
public:
//    B(int x)
//    : A(x)
//    {
//    }
    
    B(int x) try : A(x)  // 생성자에서 바로 catch를 하고 싶을떄 사용!!
    {
        // do initialization
    }
    catch (...)
    {
        cout << "Catch in B constructot" << endl;
        //throw; // 마치 이것이 작동하는 것처럼 실행됨
    }
};



int main()
{
    try
    {
        // 1
        doSomething();
        
        // 2
        B b(0);
    }
    catch (...)
    {   // function try를 constructor에서 사용할때 나타나는 중요한 특징
        // B에서 error을 잡았지만, 메인에서 한번 더 잡음(생성자에서 catch를 사용한 경우는 이렇게 됨! 주의할것!)
        cout << "Catch in main()" << endl;
    }
    
    return 0;
}
