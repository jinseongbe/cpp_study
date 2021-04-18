#include <iostream>

using namespace std;

void doSomething(const int &x);

int main()
{
    int x1 = 5;
    int &ref_x1 = x1;           // 여기서 &은 연산자가 아닌 reference를 정의해주는 문자로 사용되는것임!
    const int &ref_x2 = x1;     // 이 경우 ref_x2의 값을 바꿀 수 없음
    
    const int &ref_y = 3 + 4;   // int &ref_y = 3 + 4;는 초기화 되지 않았기 때문에 사용 불가하나, const를 붙이면 가능
    cout << ref_y << endl;
    cout << &ref_y << endl;
    
    // 그렇다면 &ref_y = 3 + 4; 이것과 y = 3 + 4; 이것의 차이는 무엇인가?
    int a = 10;
    doSomething(a);
    doSomething(10);            // reference인데 리터럴이 바로 들어 갈 수 있다!!
    doSomething(10 + a);
    doSomething(10 * 2);
    
    
    return 0;
}

void doSomething(const int &x) // const를 빼면 변수만 들어 갈 수 있지, 리터럴이 바로 들어 갈 순 없다.
{
    cout << x << endl;
}
