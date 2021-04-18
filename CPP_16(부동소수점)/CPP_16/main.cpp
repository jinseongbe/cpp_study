#include <iostream>
#include <iomanip> // 입출력을 조절한다는 의미
#include <limits>
#include <cmath>

int main()
{
    using namespace std;
    
    float f(3.141592f); // 3.14 = 31.4 * 0.1
    double d(3.141592);
    long double ld(3.141592);
    
    cout << 3.14 << endl;
    cout << 31.4e-1 << endl;
    cout << 31.4e-2 << endl;
    cout << 31.4e1 << endl;
    cout << 31.4e2 << endl;
    
    cout << numeric_limits<float>::max() << endl;
    cout << numeric_limits<float>::min() << endl; // min은 가장 작은 수의 절댓값임
    cout << numeric_limits<float>::lowest() << endl;
    cout << numeric_limits<double>::max() << endl;
    cout << numeric_limits<long double>::max() << endl;
    cout << sizeof(f) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(ld) << endl;
    
    //부동소수점에서 알아두어야 할 중요한 오류
    cout << 1.0 / 3.0 << endl; // default 자리수는 6개
    cout << std::setprecision(16); // 자리수 변경해줌
    cout << 1.0 / 3.0 << endl;
    
    float ff(123456789.0f);
    cout << std::setprecision(9);
    cout << ff <<endl; //123456792로 출력됨 - 값이 정밀도가 떨어지는 것을 인지하고 있어야함
    
    double dd(0.1);
    cout << dd << endl;
    cout << std::setprecision(17);
    cout << dd << endl; // 0.10000000000000001 로 오차 생김
    
    double d1(1.0);
    double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
    cout << setprecision(3);
    cout << d1 << endl;
    cout << d2 << endl;
    cout << setprecision(17);
    cout << d1 << endl;
    cout << d2 << endl;
    
    double zero(0.0);
    double posinf( 5.0 / zero );
    double neginf( -5.0 / zero );
    double nan = zero / zero;
    
    cout << posinf << endl;
    cout << neginf << endl;
    cout << nan << endl;
    //이런 오류가 났을때
    cout << posinf << " " << std::isnan(posinf) << endl;
    cout << neginf << " " << std::isnan(neginf) << endl;
    cout << nan << " " << std::isnan(nan) << endl;
    cout << 1.0 << " " << std::isnan(1.0) << endl;
    cout << posinf << " " << std::isinf(posinf) << endl;
    cout << neginf << " " << std::isinf(neginf) << endl;
    cout << nan << " " << std::isinf(nan) << endl;
    cout << 1.0 << " " << std::isinf(1.0) << endl;
    return 0;
}
