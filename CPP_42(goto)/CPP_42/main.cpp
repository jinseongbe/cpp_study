#include <iostream>
#include <cmath> // sqrt()
//goto는 거의 사용하지 않더라~ 반복문의 원조격 느낌
using namespace std;

int main()
{
    double x;
    
tryAgain : //label
    
    cout << "Enter a non-negative number" << endl;
    cin >> x;
    
    if(x < 0.0)
        goto tryAgain;
    
    cout << sqrt(x) << endl;
    
    return 0;
}
