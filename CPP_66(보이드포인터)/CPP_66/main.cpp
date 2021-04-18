#include <iostream>

using namespace std;

// void pointer, generic pointer - 포괄적인 포괄하는 포인터

enum Type
{
    INT,
    FLOAT,
    CHAR
};


int main()
{
    int     i = 5;
    float   f = 3.0;
    char    c = 'a';
    
    void *ptr = nullptr;
    
    ptr = &i;
    cout << ptr << endl;
    ptr = &c;
    cout << ptr << endl;
    ptr = &f;
    cout << ptr << endl;
    
    int *ptr_i = &i;
    cout << ptr_i << "\t" << *ptr_i  << endl;
    cout << ptr_i + 1 << "\t" << *ptr_i + 1 << endl;
    // void ptr은 연산을 사용 할 수 없음(void라 int인지 float인지 몰라서 포인터 연산을 할 수없음-byte를 모름)
    // dereferencing도 할 수 없음(이진수의 어떤 값이 메모리에 있는것은 알지만, int인지 float인지도 몰라서 알수가 없는것임)
    // 따라서 다시 불러오고 싶으면 강제로 casting을 해서 사용해야함
    cout << &f << " " << ptr << endl;
    cout << *static_cast<float*>(ptr) << endl;
    
    // 이렇게 사용이 불편한데 사용하는 이유?사용하는 경우가 있음(가끔!?)
    
    Type type = FLOAT; // 이렇게 까지 사용하기도 함
    cout << &f << " " << ptr << endl;
    if(type == FLOAT)
        cout << *static_cast<float*>(ptr) << endl;
    else if(type == INT)
        cout <<*static_cast<int*>(ptr) << endl;
    
    //그렇지만 현실적으로 다른 기능들이 새로 생겨서 앞으로 사용할 일은 딱히 없을지도?
    
    return 0;
}
