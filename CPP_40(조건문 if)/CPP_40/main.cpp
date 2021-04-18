#include <iostream>

using namespace std;


int min1(int x, int y)
{
    if (x > y)
        return y;
    else
        return x;
}

int min2(int x, int y)
{
    if (x > y)      return y;
    else            return x;
}

int min3(int x, int y)
{
    return (x > y) ? y : x;
}


int main()
{
    int x;

    cin >> x;

    if (x > 10)
    {
        cout << x << " is greater than 10" << endl;
        cout << "test 1 " << endl;
    }
    else
        cout << x << " is not greater than 10" << endl << endl;
    
    
    int y;
    cin >> y;
    if (1)
    {
        int y = 5; // 이 안에서 변수 선언을 해도 중괄호 밖으로 나가기 때문에 날라가버림!
    }
    else
        int y = 2;

    cout << y << endl; // 즉 출력은 입력된 값이 나오지 5나 2가 나오지 않음

    
    
    int z;
    cin >> z;

    if (z > 10)
        cout << "z is greater than 10" << endl;
    else if (z < 10 )
        cout << "z is less than 10" << endl;
    else // if (x == 0)
        cout << "z is exactly 10" << endl;
    
    
    int y1;
    cin >> y1;

    if (y1 > 10)
        cout << "a" << endl;
    else if (y1 == -1)
        return 0;
    else if (y1 < 0)
        cout << "b" << endl;
    
    
    int g;
    cin >> g;
    if (g > 0); // null statement 아무것도 실행하지 않을때 ';'를 if문 뒤에 붙여준다.
    
    
    if (g = 0) // 이것은 g에 0을 대입하고 if( g )를 실행히시키는 것이기 때문에 꼭 ==로 쓰자!
    {
        cout << g << endl;
    }
    
    return 0;
}
