#include <iostream>

int main()
{
    using namespace  std;
    
    float pi = 3.14f;
    const float pii = 3.14f; // 바꿀수 없는 변수
    float piii = 3.14l; // longdouble
    int i = -1234U; // unsigned로 바꿔줌 근데 차라리 케스팅 하는걸 추천함
    unsigned int n = 5u;
    long n2 = 5L;
    double d = 6.0e-10;
    
    //Decomal   : 0 1 2 3 4 5 6 7 8 9 10 / 11 12 13 14 15 16
    //Octal     : 0 1 2 3 4 5 6 7 8 / 10 11 12 13 14 15
    //Hexa      : 0 1 2 3 4 5 6 7 8 9 A B C D E F / 10 11 12
    
    //octal
    int x = 012; // '0'이 8진수임을 알려줌
    cout << x << endl;
    
    //hexa
    int y = 0xF;
    cout << y << endl;
    
    //binary
    int z = 0b1010;
    int zz = 0b1011'1001'1010; // '를 컴파일러가 인식하지 않아서 보기 좋게 쓸 수 있음 10진법에도 사용가능.
    cout << z << endl;
    cout << zz << endl;
    
    
    int num_items = 123;
    int price = num_items * 10; // 매직넘버를 남겨놓는 경우
    
    const int price_per_item = 10;
    int price2 = num_items * price_per_item; //  이런식으로 쓰는게 더 좋음
    
    return 0;
}
