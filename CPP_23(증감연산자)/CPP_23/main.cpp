#include <iostream>

int add(int a, int b);

int main()
{
    using namespace std;
    
    int x = 5;
    int y1 = ++x; // x + 1
    int y2 = --x; // x - 1
    int z1 = x++;
    
    cout << y1 << endl;
    cout << y2 << endl;
    cout << z1 << endl << endl;
    
    
    //중요
    int _x = 6, _y = 6;
    cout << _x << " " << _y << endl;
    cout << ++_x << " " << --_y << endl; // 1을 증가시킨다음 _x을 처리한다
    cout << _x << " " << _y << endl;
    
    _x = 6;
    _y = 6;
    cout << _x << " " << _y << endl;
    cout << _x++ << " " << _y-- << endl; // _x를 처리한 다음에 1을 증가시킨다
    cout << _x << " " << _y << endl << endl;
    
    //부작용이 될 수 있는 부분
    int xx = 1;
    int v = add(xx, ++xx); // 컴파일러에 따라 3 또는 4가 나올 수 있음 따라서 사용하지말라!!
    cout << v << endl << endl;
    
    int xxx = 1;
    xxx = xxx++; // 정의 되지 않기 때문에 이렇게 사용하지 말것!
    cout << xxx << endl;
    
    return 0;
}

int add(int a, int b)
{
    return a + b;
}
