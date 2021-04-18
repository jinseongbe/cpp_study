#include <iostream>
#include "MyConstant.h"

using namespace std;


int GlobalVariable(600); // 전역변수, 다른 cpp파일에서도 사용 할 수 있다(외부연결,ExternalLinkage)
static int g_a(0); // 정적변수는 다른 cpp파일에서 접근 할 수 없다.
                   // Internal linkage

void doSomething();
void static_doSomething();

// forward declaration
extern void dododo();   // extern은 생략되도 사용가능하다! 외부 cpp 파일에서 몸을 찾아온다!
extern int A;           // 변수도 같은 원리로 사용 가능하다! 외부에서 찾아옴, 그러나 없으면 linking error남!
                        // 몸체가 없다는 뜻은 메모리를 가지고 있지 않다는 뜻이다.


int main()
{
    int localVariable(0); // 지역변수: 블록을 벗어나면 메모리에서 os로 반납됨
    
    
    cout << "전역변수 " << GlobalVariable << endl;
    int GlobalVariable(1); // 전역변수랑 같은 이름으로 지역변수를 사용하면 이름가리기가 발생함
    cout << "NameHiding,Shadowing : 지역변수 " << GlobalVariable << endl;
    cout << "전역변수를 사용하기 위한 방법 '::' " <<::GlobalVariable << endl; // 전역 변수를 불러오기 위한 기호 '::'
    
    
    doSomething();
    doSomething();
    doSomething();
    doSomething();
    cout << endl;
    static_doSomething();
    static_doSomething();
    static_doSomething();
    static_doSomething();
    cout << endl;
    
    //linkage
    cout << A << endl; // 만약 같은 이름의 변수를 사용하면 오류남! 주의!
    dododo(); // test.cpp 파일에서 불러옴
    cout << "In main.cpp file pi " << Constants::pi << endl;
    cout << "In main.cpp file pi address " << &Constants::pi << endl;
    //같은 헤더파일에서 불러온 pi의 주소가 다르다!!!!! 메모리 낭비로 이어짐!
    //방지하는 방법은 cpp파일로 정의해서 헤더에서는 초기화만 해주면 주소가 동일해짐(MyConstants.cpp)
    
    return 0;
}


void doSomething()
{
    int a = 1;
    ++a;
    cout << a << endl;
}

void static_doSomething()
{
    static int a = 1; // 정적변수: 변수가 받은 메모리가 static 이라는 뜻!, 즉 static 변수는 처음에 초기화하지 않으면 작동하지 않음!!, debuging 할때 유용하게 사용되고, 실 사용에서는 좀 주의해서 사용 할 것! : 전역변수도 같은 방법으로 사용 가능
    ++a;
    cout << a << endl;
}
