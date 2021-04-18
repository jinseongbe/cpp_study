#include <iostream>
#include "My_Constants.h"

#define PRICE_PER_ITEM 30 // 매크로는 거의 안씀, c++에 넘어와서는

using namespace std;

void printNumber(int my_number);



int main()
{
    const double gravity{ 9.8 }; // 컴파일 타임 상수 : 만들면서 정의해줌
    double const gravity2{ 9.8 }; //이렇게 사용 가능하지만 보통은 앞에 사용
    //gravity = 1.2; // 빌드 되지 않음
    
    
    printNumber(123);
    
    
    int number;
    cin >> number;
    const int special_number(number); // 런 타임 상수 : 실행되면서 입력되는 값
    constexpr int my_const(123); // 컴파일 타임 상수라는 것을 정확히게 하는 법임
    
    
    int num_item(123);
    int pprice = num_item * PRICE_PER_ITEM; //이렇게 쓰지 않음 요즘음!
    
    double radios;
    cin >> radios;
    double circumference = 2.0 * constants::pi * radios; // 해더파일에서 const 상수를 불러옴
    
    return 0;
}

void printNumber(const int my_number) // 함수 내부에서 수정하지 못하도록 사용함, 이렇게 많이 사용함
{
    cout << my_number << endl;
}
