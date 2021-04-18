#include <iostream>

int main()
{
    using namespace std;
    
    // logical NOT
    bool x = true;
    cout << !x << endl << endl;
    
    // logical AND
    bool x1 = true;
    bool y1 = false;
    cout << (x1 && y1) << endl;
    cout << (x1 && x) << endl << endl;
    
    // logical OR
    bool x2 = true;
    bool y2 = false;
    cout << (x2 || y2) << endl;
    cout << (y1 || y2) << endl << endl;
    
    
    // Notice! short circuit evaluation
    int x0 = 2; // x0가 1일때는 y가 증가되지만 x0가 2일때는 y가 증가되지 않음!
    int y0 = 2;
    
    if (x0 == 1 && y0++ == 2) // 왼쪽에서 false가 나올경우 &&연산은 오른쪽 항을 계산하지 않음!!
    {
        // do something
    }
    
    cout << y0 << endl << endl;
    
    //De Morgan's Law
    bool xx = true;
    bool yy = false;
    
    cout << !(xx && yy) << endl;
    cout << (!xx && !yy) << endl;
    cout << !(xx || yy) << endl << endl;
    
    // XOR
    // false : false = false
    // false : true  = true
    // true  : false = true
    // true  : true  = false
    // cpp에는 XOR연산이 없기 떄문에 다르게 사용해야한다.
    bool a = true;
    bool b = true;
    
    cout << (a != b) << endl << endl;
    
    // 논리연산자의 순서!
    bool v1 = true;
    bool v2 = false;
    bool v3 = false;
    
    bool r1 = v1 || v2 && v3; //논리연산자의 우선순위가 &&이 ||보다 우선이므로 괄호를 사용해서 표시해주는게 좋다!
    bool r2 = (v1 || v2) && v3;
    bool r3 = v1 || (v2 && v3);
    
    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    
    return 0;
}
