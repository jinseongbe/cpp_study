#include <iostream>
#include <cmath>
#include <limits>

int main()
{
    using namespace std;
    
    short       s = 1;      // 2 byte = 2 * 8 bits = 16 bits
//    int         i = 1;
//    long        l = 1;
//    long long   ll = 1;
    
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    cout << "\n" << endl;
    
    cout << std::pow(2, sizeof(short) * 8 - 1 ) - 1 << endl;
    cout << std::numeric_limits<short>::max() << endl;
    cout << std::numeric_limits<short>::min() << endl;
    cout << std::numeric_limits<short>::lowest() <<endl;
    cout << "\n" << endl;
    
    s = 32767;
    s = s + 1; // 32768
    cout << s << endl; // -32768이 나옴 : overflow 현상
    s = -32768;
    s = s - 1;
    cout << s << endl; // 32767이 나옴 : overflow 현상
    cout << "\n" << endl;
    
    cout << std::pow(2, sizeof(int) * 8 - 1 ) - 1 << endl;
    cout << std::numeric_limits<int>::max() << endl;
    cout << std::numeric_limits<int>::min() << endl;
    cout << std::numeric_limits<int>::lowest() << endl;
    cout << "\n" << endl;
    
    unsigned int p = -1;
    cout << p << endl; // 최대값이 나옴 : overflow 발생
    cout << 22 / 4 << endl; // 정수끼리 연산에서는 결과가 정수로 나옴
    cout << (float)22 / 4 << endl; // 22가 실수이므로 실수로 나옴
    
    return 0;
}
