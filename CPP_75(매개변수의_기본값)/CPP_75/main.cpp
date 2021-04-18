#include <iostream>
#include <string>

using namespace std;
void printDecle1(int z);        // 위에서 디컬러레이션 하고 싶을 경우 함수 또는 위에서 한번만 기본값을 해줘야함!
void printDecle2(int z = 100);  // in header :  보통 해더파일에서 기본값은 선언해준다

void print(int x = 0)
{
    cout << x << endl;
}

void printMult(int x = 10, int y = 20, int z = 30) // z에 기본값을 안넣고 y에만 기본값을 넣으면 오류가 발생한다!
{
    cout << x << y << z << endl;
}

int main()
{
    print(10);
    print();
    
    printMult();
    printMult(100);
    printMult(100, 200);
    printMult(100, 200, 300);

//    printDecle1();
    printDecle2();
    
    return 0;
}

void printDecle1(int z = 10)
{
    cout << z << endl;
}

void printDecle2(int z)
{
    cout << z << endl;
}
