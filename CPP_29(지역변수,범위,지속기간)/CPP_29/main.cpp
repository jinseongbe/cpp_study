#include <iostream>
using namespace std;

namespace work1
{
    int a = 1;

    void doSomething()
    {
        a += 3;
    }
}

namespace work2
{
    int a = 1;

    void doSomething()
    {
        a += 5;
    }
}

namespace test
{
    namespace test1
    {
        namespace test2
        {
            void print_()
            {
                cout << "only c++ 17" << endl;
            }
        }
    }
}

namespace testt::testt2::testt3
{
    void printSomething()
    {
        cout << "only c++ 17 !!" << endl;
    }
}


int main()
{
    int apple = 5;
    
    {
        int apple = 1; // 블럭이 사라지면 없어지는 변수, 그러나 이름을 다르게 사용하라!!
        cout << apple << endl;
    }
    
    cout << apple << endl << endl;
    
    cout << work1::a << endl;
    work1::doSomething();
    cout << work1::a << endl << endl;
    
    cout << work2::a << endl;
    work2::doSomething();
    cout << work2::a << endl;
        
    test::test1::test2::print_();
    testt::testt2::testt3::printSomething();
    
    return 0;
}
