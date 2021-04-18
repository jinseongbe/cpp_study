#include <iostream>
#include <typeinfo>
#include <iomanip>

int main()
{
    using namespace std;
    
    int a(123.0);       // 암시적형변환: double로 바꿔버림
    cout << typeid(a).name() << endl;
    
    //numeric promotion
    float b1 = 1.0f;
    double b2 = b1;     // 메모리가 커진곳으로 갔기 때문에 큰 문제가 없음
    
    //numeric conversion
    double c = 3;       // 타입이 바뀌는 경우
    char d = 30000;     // 크기가 작아지는 경우
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
    cout << static_cast<int>(d) << endl; // 30000이 48로 바뀜! 그러나 컴파일은 됨 그러니까 주의해야함!!
    
    double e1 = 0.123456789;
    float e2 = e1;
    cout << std::setprecision(12) << e1 << endl;
    cout << std::setprecision(12) << e2 << endl << endl;
    
    int i1 = 1234;
    float i2 = i1;
    cout << std::setprecision(12) << i1 << endl;
    cout << std::setprecision(12) << i2 << endl << endl;
    
    float f1 = 3.14f; // 암시적형변환에서는 소수점을 버린다, 반올림함수는 따로 있다!
    int f2 = f1;
    cout << std::setprecision(12) << f1 << endl;
    cout << std::setprecision(12) << f2 << endl << endl;
    
    //unsign 문제
    cout << 5u - 10 << endl;        // u는 unsigned를 의미함 즉 (-5 - 10)
    cout << 5u - 10u << endl;
    cout << 5 - 10 << endl;
    
    // 형변환 우선순위
    // int, unsigned int, long, unsigned long
    // long long, unsigned long long, float, double, long double
    // 위와 같은 우선순위 때문에 내부적으로 int로 바꾸지 않음
    
    //casting
    int x = (int)4.0;   // c style casting
    int z = int(3.0);   // cpp style casting
    int y = static_cast<int>(5.0); // recent casting style
    
    
    
    return 0;
}
