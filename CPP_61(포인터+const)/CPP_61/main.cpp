#include <iostream>

using namespace std;

int main()
{
    const int value = 5;
    const int *ptr = &value;
//    * ptr = 6;              // const는 가능하나 dereferencing이 불가능해짐!
                              // value가 const이기 때문에!
    cout << *ptr << endl;
    cout << endl << endl;
    
    
    
    int value2 = 6;
    const int *ptr2 = &value2;// 포인터 값은 못바꾸지만 원래 값인 int value2를 바꿔주면 포인터값도 바뀜!
    
    cout << *ptr2 << endl;
    
    value2 = 60;
    
    cout << *ptr2 << endl;
    cout << endl << endl;
    
    
    
    int value3 = 10;
    const int *ptr3 = &value3;
//    *ptr3 = 6;               // 포인터주소에 들어있는 값을 직접적으로 바꿀수없다!(역참조불가!)
    cout << *ptr3 << endl;
    cout << (uintptr_t)ptr3 << endl;
    
    int value4 = 20;
    ptr3 = &value4;
    
    cout << *ptr3 << endl;
    cout << (uintptr_t)ptr3 << endl;
    
    
    
    int value5 = 90;
    int *const ptr4 = &value5;

    *ptr4 = 10;
    cout << *ptr4 << endl;
    
    int value6 = 8;
//    ptr4 = &value6; // 포인터의 주소를 바꾸는 것은 불가능함! 진정한 변수로써 포인터 const라고 생각되어짐!
    
    
    
    int value7 = 10;
    const int *const ptr5 = &value7; // 이건 포인터의 주소도 내용도 바꿀수 없음!
    
    return 0;
}
