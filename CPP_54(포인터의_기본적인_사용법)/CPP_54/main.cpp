#include <iostream>
#include <typeinfo>
using namespace std;

struct Something
{
    int  a, b, c, d;
};

int main()
{
    int x = 5;
    
    cout << x << endl;
    cout << &x << endl;     // & : address-of operator
    cout << (long long)&x << endl;
    
    // de-reference operator '*' : 그 주소에 있는것을 찾아 보는것
    cout << *(&x) << endl;
    cout << *&x << endl;    // 얀산자 우선순위에 의해서 괄호를 사용 안해도 됨
 
    
    // pointer : 주소를 저장하는 변수
    int *ptr_x1;
    ptr_x1 = &x;
    
    int *ptr_x2 = &x, *ptr_x3 = &x; // 각각 스타를 붙여줘야 포인터로 정의된다! 주의!
    
    typedef int* pint;
    pint ptr_y1 = &x, ptr_y2 = &x;  // 너무 많으면 이런식으로 쓰기도 하지만 보편적으로는 그냥 *로 표시함!
    
    cout << ptr_x2 << endl;
    cout << *ptr_x2 << endl;
    
    
    // pointer를 사용하는 이유 : 1. array에 수많은 데이터를 복사해서 사용하지 않고 찾아 쓰기 위함
    //                       2. 변수를 그 자체로 여기저기 사용하기 보단 주소로 대신 사용하기 위함
    
    
    double d = 1.0;
    
//    int *ptr_z1 = &d; // 형식이 다르면 오류남!!
    double *ptr_z2 = &d;
    
    cout << ptr_z2 << endl;
    cout << *ptr_z2 << endl;
    cout << typeid(ptr_z2).name() << endl;
    cout << typeid(ptr_x1).name() << endl;
    
    
    cout << sizeof(x) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(&x) << " " << sizeof(ptr_x1) << endl; // 주소는 저장된 변수의 크기와 상관없이 동일함!
    cout << sizeof(&d) << " " << sizeof(ptr_z2) << endl; // 32bits는 4byte 64bits는 8byte
    
    Something ss;
    Something *ptr_s;
    cout << sizeof(Something) << endl;
    cout << sizeof(ptr_s) << endl;                        // 구조체의 주소도 8byte
    
    
    //포인터 문제가 생길 수 있는 경우!
    int *ptr_v1;        //주소를 정의해주지 않음! 실행은 되고 오류 발생이니 주의할것!
    cout << *ptr_v1 << endl;
    
    return 0;
}



