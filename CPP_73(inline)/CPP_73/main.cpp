#include <iostream>

using namespace std;

inline int min(int x, int y)
{
    return x > y ? y : x;
}

int main()
{
    cout << min(5, 6) << endl;
    cout << min(3, 2) << endl;
    
    // inline으로 사용한 경우 위의 함수를 다음과 같이 컴파일러가 인식함
    cout << (5 > 6 ? 6 : 5) << endl;
    cout << (3 > 2 ? 2 : 3) << endl;
    
    // 그러나 이것은 강제하는 것이 아니라 권장 정도이기 때문에, 컴파일러가 실행 할지 안할지 알아서 판다하는 경우가 많음
    // 즉 컴퓨터가 이것을 인라인으로 실행할지 안할지는 확실히 알 수 없다.
    // 또한 컴파일이 된 프로그램의 크기가 커진다 - 너무 커지면 메모리가 왔다갔다 해서 오히려 느려질 가능성도 있다.
    // 최근에는 더욱이 컴퓨터가 알아서 처리하기 때문에 굳이 inline을 사용 하지 않아도 좋을듯 한것으로 생각된다.
    
    return 0;
}
