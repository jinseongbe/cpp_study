#include <iostream>

int main()
{
    using namespace std;
    
    int x = 7;
    int y = 5 - x; // - x 라고 하기보다는 -x로 표기하는것이 좋다. 보기 헷갈리니까
    int z = x % y;
    double yy = 5 - x;
    
    cout << x / y << " " << z << endl;
    cout << x / yy << endl; // 하나만 실수여도 결과가 실수로 출력됨
    
    // 주의사항
    cout << -5 / 2 << endl; // -2.5이면 버림을 해서 -2로 출력함! c++ 11 부터임
    cout << -5 % 2 << endl; // 나머지 연산의 결과는 왼쪽에 있는 부호를 따르기로 정하였다고 함
    cout << 5 % -2 << endl << endl; //
    
    int zz = 10;
    zz += 2; // zz = zz + 2
    cout << zz << endl;
    zz = 10;
    
    zz -= 2; // zz = zz - 2
    cout << zz << endl;
    zz = 10;
    
    zz *= 2; // zz = zz * 2
    cout << zz << endl;
    zz = 10;
    
    zz %= 2; // zz = zz % 2
    cout << zz << endl;
    
    return 0;
}
