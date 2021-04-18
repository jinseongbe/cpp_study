#include <iostream>

using namespace std;

// 매크로는 보통 대문자로 씀 : 매크로는 코드에서 대체시킴, 요즘은 잘 안씀
// 해당 파일에서만 작동, 다른 파일로 옮기면 작동하지 않음
#define MY_NUMBER 9
#define TEXT "hello"
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define LIKE_APPLE // 조건에 맞춰서 다르게 컴파일 할때 사용 ex)os가 여러개인 곳에서 사용하려고 할때

int main()
{
    cout << MY_NUMBER << endl;
    cout << TEXT << endl;
    cout << MAX(1 + 5, 3) << endl;
    
    #ifdef LIKE_APPLE
    cout << " APPLE " << endl;
    #endif

    #ifndef LIKE_APPLE
    cout << " orange " << endl;
    #endif
    
    #ifdef LIKE_APPLE
    cout << " APPLE " << endl;
    #else
    cout << " orange " << endl;
    #endif
    
    
    return 0;
}
