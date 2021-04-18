#include <iostream>

using namespace std;
void doSomething1(int n);
void doSomething2(int &m);
void doSomething3(const int &m);
void printElements(int (&arr)[5]);

struct A_0
{
    int v1;
    float v2;
};

struct a_0
{
    A_0 st;
};

int main()
{
    int value = 5;
    int *ptr1 = nullptr;
    ptr1 = &value;
    cout << endl;
    
    
    int &ref = value;  //
    cout << ref << endl;
    
    ref = 10;           // *ptr = 10;
    
    cout << value << " " << ref << endl;
    
    cout << &value << endl;
    cout << &ref << endl;
    cout << ptr1 << endl;
    cout << &ptr1 << endl << endl;
    
    
//    reference의 특징
//    int &ref1; (x) // 반드시 초기화가 되어야 사용 되어진다,
//    int &ref1 = 104; (x) // 리터러쳐는 들어갈 수 없다. 변수의 주소가 들어가야 함으로! 당연한사실!
    int x = 5;
    int &ref1 = x;
    const int y = 8;
//    const int &ref1 = y; // const를 뺴면 컴 파일이 안됨! 포인터의 const 문제와 같은 것임! 근데 안됨?!?!
    
    
    int value1 = 5;
    int value2 = 10;
    
    int &ref2 = value1;
    
    cout << ref2 << endl;
    cout << &ref2 << endl;
    cout << &value1 << endl;
    cout << &value2 << endl << endl;
    
    ref2 = value2;
    
    cout << ref2 << endl;
    cout << &ref2 << endl;      //여기서 주소는 value1의 주소임!
    cout << &value1 << endl;
    cout << &value2 << endl ;
    cout << value1 << endl << endl;
    
    
    int n = 5;
    int m = 5;
    
    cout << n << endl;
    cout << m << endl;
    
    doSomething1(n);        // 포인터나 참조를 쓰지 않으면 함수가 끝나면서 변수가 없어짐
    doSomething2(m);        // 포인터의 경우는 포인터 자체가 하나의 변수로 주소를 복사하여 메모리를 차지하지만
                            // 참조의 경우 변수의 주소를 그대로 가져와 쓰기 때문에 퍼포먼스와 사용이 편리하다!
    doSomething3(m);        // 이 경우는 변수를 안에서 바꿔줄수없음! 사용자가 못바꾸도록 함수를 만들때 사용!
    
    cout << n << endl;
    cout << m << endl;
    
    
    
    const int length = 5;
    int arr[length] = { 1, 2, 3, 4, 5};
    
    printElements(arr);
    
    
    
    a_0 ot;
    ot.st.v1 = 1.0;
    cout << ot.st.v1 << endl;
    // reference를 사용하면
    int &v1 = ot.st.v1;
    v1 = 1.0;
    cout << v1 << endl;
    
    
    
    int valuee = 5;
    int *const ptr = &valuee;
    int &reff = valuee;
    
    cout << &valuee << endl;
    cout << ptr << endl;
    cout << &ptr << endl;
    cout << &reff << endl;
    
    
    return 0;
}


void doSomething1(int n)
{
    n = 10;
    cout << "In Dosomething(int) " << n << endl;
}

void doSomething2(int &m)
{
    m = 10;
    cout << "In Dosomething(ref) " << m << endl;
}

void doSomething3(const int &m)
{
//    m = 10;
    cout << "In Dosomething(ref) " << m << endl;
}

void printElements(int (&arr)[5])       // 요소의 개수[5]를 꼭 넣어줘야함!
{
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

