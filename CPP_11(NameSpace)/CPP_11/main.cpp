#include <iostream>

using namespace std;

namespace  MySpace1
{
    int doSomething(int a, int b)
    {
        return a + b;
    }
}

int doSomething(int a, int b)
{
    return a * b;
}

using namespace MySpace1;

int main()
{
//    cout << doSomething(3, 4) << endl;
    cout << MySpace1::doSomething(3, 4) << endl;
    
    return 0;
}
