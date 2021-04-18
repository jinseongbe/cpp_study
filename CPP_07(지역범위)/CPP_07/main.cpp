#include <iostream>

using namespace std;

void dosomething(int x)
{
    x = 123;
    cout << x << "\t" << &x << endl;
}

int main()
{
    /*
    int x(0); // x = 0;
    
    cout << x << " " << &x << endl;
    
    {
        // 영역 분리용으로 사용 가능
        int x(1); // 이 x는 다른 메모리에 대한 식별자이다. 변수는 괄호가 끝나면 메모리에서 사라짐
        cout << x << " " << &x << endl;
        
    }
    
    {
//        int x(2);
        x = 2; // 이건 원래 주소에 값을 변경햐준것
        cout << x << " " << &x << endl;
    }
    
    cout << x << " " << &x << endl;
    */
    
    int x(0);
    
    cout << x << "\t" << &x << endl;
    dosomething(x);
    cout << x << "\t" << &x << endl;
    
    return 0;
}
