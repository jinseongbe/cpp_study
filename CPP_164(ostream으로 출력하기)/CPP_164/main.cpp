#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // 1. setf(), unsetf()
    cout.setf(std::ios::showpos);    // std::ios::showpos : +기호 나타내기
    cout << 108 << endl;
    
    cout.unsetf(std::ios::showpos);
    cout << 109 << endl;

    
//    cout.unsetf(std::ios::dec);     // 10진수 모드를 끄는 방법
//    cout.setf(std::ios::hex);       // std::ios::hex : 16진수 표현
//    cout << 108 << endl;

    cout.setf(std::ios::hex, std::ios::basefield);  // 이렇게 쓰면 10진수모드를 끄지 않고 바로 사용 가능!
    cout << 110 << endl;
    
    cout << std::hex;        // 위에 방법이 귀찮으면 그냥 이렇게 쓰면 됨!
    cout << 110 << endl;
    cout.setf(std::ios::uppercase); // 대문자로 출력해줌!
    // cout << std::hex << std::uppercase; // 이렇게도 사용 가능 (#include <iomanip>)
    cout << 110 << endl;
    
    cout << std::dec;
    cout << 135 << endl;
    
    
    
    // 2. std::boolalpha
    cout << std::boolalpha;
    cout << true << " " << false << endl;
    
    
    
    // 3. setprecision() : 정밀도
    cout << std::defaultfloat; // 기본 모드
//    cout << std::fixed;     // 소수점 뒤자리 고정 모드
//    cout << std::scientific << std::uppercase;    // e 표기, uppercase로 대문자로 변경 가능
//    cout << std::showpoint;   // 소수점 뒷자리가 없어도 점을 표기해줌  123 -> 123.
    cout << std::setprecision(3) << 123.456 << endl;
    cout << std::setprecision(4) << 123.456 << endl; // 반올림되어서 출력됨
    cout << std::setprecision(5) << 123.456 << endl;
    cout << std::setprecision(6) << 123.456 << endl;
    cout << std::setprecision(7) << 123.456 << endl;
    
    
    
    // 4. setw(), std::left, std::right, std::internal, cout.fill
    cout << -12345 << endl;
    cout.fill('*');
    cout << std::setw(10) << -12345 << endl;
    cout << std::setw(10) << std::left << -12345 << endl;
    cout << std::setw(10) << std::right << -12345 << endl;
    cout << std::setw(10) << std::internal << -12345 << endl;
    
    return 0;
}
