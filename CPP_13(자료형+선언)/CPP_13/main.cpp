#include <iostream>
#include <bitset>

using namespace std;

int main()
{
//    using namespace std;
    
    int j = 3;
    int i = -1;
    int k = 123;
    char a_ = 'H';
    
    cout << (uintptr_t)static_cast<void*>(&a) << endl;
    cout << (uintptr_t)static_cast<void*>(&i) << endl;
    
    //----------------------------------------------
    
    bool bValue = false;
    cout << (bValue ? 1 : 0) << endl;
    
    char chValue_a = 'A';
    char chValue_b = 65;
    cout << chValue_a << endl;
    cout << (int)chValue_a << endl;
    cout << chValue_b << endl;
    
    float fValue = 3.141592f; // f 빼놓으면 double로 컴퓨터가 사용함
    double dValue = 3.141592;
    cout << fValue << endl;
    cout << dValue << endl;
    
    //modern c++에서 생긴거
    auto aValue = 3.141592;
    auto aValue2 = 3.141592f;
    cout << sizeof(aValue) << endl;
    cout << sizeof(aValue2) << endl;
    
    //sizeof
    cout << sizeof(bool) << endl;
    cout << sizeof(bValue) << endl;
    
    //초기화하는 방법
    int a = 123;    //1.copy initialization
    int b(123);     //2.direct initialization
    int c{ 123 };   //3.uniform initialization, 최근에 권장하기도 한다
    
    int d = (int)3.1415; // 인위적캐스팅(형변환) - 안할경우 워닝만 생김
    int e((int)3.1415); // 인위적캐스팅 - 안할경우 워닝만 생김
//    int f{3.1415}; // 에러가 뜨고 컴파일이 되지 않음.
    
    //여러개 동시에 선언
    int f, g, h(8), y = 16; // 헷갈려 보이기 때문에 권장하지 않는 방식임, 모두 따로 초기화하는것이 좋음
    
    //선언하는 타이밍
    //과거에는 맨 위에 다 써줬지만, 요즘에는 사용하기 바로 위에 선언해주는 식으로 함
    

    
    
    return 0;
}
