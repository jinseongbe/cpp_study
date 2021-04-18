#include <iostream>

using namespace std;

void foo1(int *ptr);

int main()
{
    int value = 5;
    int *ptr_value = &value;
    cout << value << " " << &value << endl;
    
    
    foo1(ptr_value);
    foo1(&value);
//    foo1(5);            // 리터럴은 안됨! 함수 input을 리터럴로 받아도 컴파일 오류뜸!
    
    cout << &ptr_value << endl;
    cout << value << endl;
    return 0;
}

void foo1(int *ptr)
{
    cout << *ptr << " " << ptr << " " <<  &ptr << endl;
    *ptr = 10;
}

void foo2(const int *ptr)
{
    cout << *ptr << " " << ptr << " " <<  &ptr << endl;
//    *ptr = 100;     //const 변수로 넣은경우 변경 불가!
}
