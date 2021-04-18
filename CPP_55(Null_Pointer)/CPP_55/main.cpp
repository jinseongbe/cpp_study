#include <iostream>
#include <cstddef>

using namespace std;

void doSomething(double *ptr)
{
    cout << "address of pointer variable in doSomething()" << &ptr << endl;
    
    if(ptr != nullptr)
    {
        // do something usefull
        cout << *ptr << endl;
    }
    else
    {
        // do nothing with ptr
        cout << "Null ptr, do nothing" << endl;
    }
}



int main()
{
    double *ptr1 = 0;        // c-style
    double *ptr2 = NULL;     // c-style
    double *ptr3 = nullptr;  // modern c++ style
    double *ptr4{ nullptr };
    
    doSomething(ptr4);
    doSomething(nullptr);
    
    double d = 123.4;
    doSomething(&d);
    
    ptr1 = &d;
    doSomething(ptr1);
    
    
    cout << "address of pointer variable in main()" << &ptr1 << endl;
    // 함수 파라미터에 들어간 포언터 변수는 다른 메모리를 사용하여 주소로 메모리에 만들어지고 사용된 후 사라짐
    
    std::nullptr_t nptr;    // null ptr 밖에 넣을 수 없음! : #include <cstddef>
    
    
    return 0;
}
