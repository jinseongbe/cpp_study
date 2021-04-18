#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    
//    int x;
//    int y;
//
//    cin >> x >> y;
//    cout << "Your input values are : " << x << " " << y << endl << endl;
//
//    if (x == y)
//        cout << "equal" << endl;
//    if (x != y)
//        cout << "not equal" << endl;
//    if (x > y)
//        cout << "x is greater than y" << endl;
//    if (x < y)
//        cout << "x is less than y" << endl;
//    if (x >= y)
//        cout << "x is greater than y or equal to y" << endl;
//    if (x <= y)
//    cout << "x is less than y or equal to y" << endl;
//
//    cout << endl;
    
    // 주의할점!! 부동소수점에서 생기는 대소비교 문제!
    double d1(100 - 99.99); // 0.001
    double d2(10 - 9.99);   // 0.001
    
    if (d1 == d2)
        cout << "equal" << endl;
    else
    {
        cout << "not equal" << endl;
        
        if (d1 > d2) cout << "d1 > d2" << endl;
        else
            cout << "d1 < d2" << endl;
    }
    
    cout << d1 << endl;
    cout << d2 << endl;
    
    
    //수치해석학 관점에서 해결법, 오차의 한계를 정의한다!
    cout << std::abs(d1 - d2) << endl;
    
    const double epsilon = 1e-15;
    if (std::abs(d1 - d2) < epsilon)
        cout << "Approximately equal" << endl;
    else
        cout << "Not equal" << endl;
    
    return 0;
}
