#include <iostream>
#include <bitset>

int main()
{
    using namespace std;
    
    /*
     10진법
        0   = (10^2)*0 + (10^1)*0 + (10^0)*0
        1   = (10^2)*0 + (10^1)*0 + (10^0)*1
        2   = (10^2)*0 + (10^1)*0 + (10^0)*2
        14  = (10^2)*0 + (10^1)*1 + (10^0)*4
        47  = (10^2)*0 + (10^1)*4 + (10^0)*7
        121 = (10^2)*1 + (10^1)*2 + (10^0)*1
     
     2진법
        0 = (2^2)*0 + (2^1)*0 + (2^0)*0 = 000
        1 = (2^2)*0 + (2^1)*0 + (2^0)*1 = 001
        2 = (2^2)*0 + (2^1)*1 + (2^0)*0 = 010
        3 = (2^2)*0 + (2^1)*1 + (2^0)*1 = 011
        4 = (2^2)*1 + (2^1)*0 + (2^0)*0 = 100


     음의 정수의 표현
     
     -5
     
     0000 0101
     보수 complement
     1111 1010 // 0과 1을 바꿔줌
     1111 1011 // 바꿔준 결과에 1을 더함 == -5, 여기서 맨 앞의 0,1은 부호를 의미함
     
     1을 더하는 이유
     
     0000 0000 : 양의 zero
     1111 1111 : 양의 zero에 보수, 이럴경우 0이 두가지로 표현됨
     0000 0000 : 1을 더하면 음의 zero가 양의 zero와 같게됨 따라서 1을 더해줌
     
     음의 이진법수를 10진법으로 바꾸는 방법
     1111 1011 (-5)
     보수 취함
     0000 0100 // 부호 -됨
     0000 0101 // 1을 더해줌 == -5
     
     signed     vs  unsigned
     1001 1110  vs  1001 1110 (맨앞의 0,1이 부호를 의미하냐 안하냐의 차이!)
     -98        vs  158
     
     */
    
    // Bitwise Operators (원래 이게 기본형임!, unsigned를 사용하는게 기본)
    // '<<' left shift, '>>' right shift
    // '~', '&', '|', '^'
    
    // shift(<<,>>)
    unsigned int a = 3;
    cout << std::bitset<8>(a) << " " << a << endl;
    
    unsigned int b = a << 3; // 패턴을 숫자만큼 밀고 빈칸을 0으로 채운다. 원래 숫자에 2배씩 된다!, 속도가 pow보다 훨씬빠름
    cout << std::bitset<8>(b) << " " << b << endl << endl;
    
    unsigned int c = 128;
    cout << std::bitset<8>(c >> 0) << " " << (c >> 0) << endl;
    cout << std::bitset<8>(c >> 1) << " " << (c >> 1) << endl;
    cout << std::bitset<8>(c >> 2) << " " << (c >> 2) << endl;
    cout << std::bitset<8>(c >> 3) << " " << (c >> 3) << endl;
    cout << std::bitset<8>(c >> 4) << " " << (c >> 4) << endl << endl;
    
    // not(~)
    unsigned int d = 64;
    cout << std::bitset<8>(d) << " " << (d) << endl;
    cout << std::bitset<8>(~d) << " " << (~d) << endl << endl;
    
    // 이진수 입력법
    int x = 0b1100;
    int y = 0b0110;
    cout << "x : " << std::bitset<4>(x) << endl;
    cout << "y : " << std::bitset<4>(y) << endl;
    
    // AND : '&', OR : '|', XOR : '^'
    cout << "AND : " << std::bitset<4>(x & y) << endl;
    cout << "OR  : " << std::bitset<4>(x | y) << endl;
    cout << "XOR : " << std::bitset<4>(x ^ y) << endl;
    
    // x = x & b; 결합형으로 사용가능!
    
    return 0;
}
