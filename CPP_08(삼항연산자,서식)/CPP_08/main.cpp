#include <iostream>

using namespace std;

int main()
{
    int n(10); //여백을 띄우는 것 : indenting
    int x(-2); // x is a variable, 2 is a literal.
    
    cout << 1 + 2 << endl; // 1 and 2 are literal.
    cout << x + 2 << endl;
    
    // ternary operator:유일한 삼항 연산자
    int y = (x > 0) ? 1 : 2;
    
    cout << y << "\t" << n << endl;
    
    return 0;
}
