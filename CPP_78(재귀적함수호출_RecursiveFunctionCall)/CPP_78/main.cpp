// 재귀적 함수 호출(Recursive Function Call)
// : 이름이 똑같은 함수를 다시 호출하는 것, stackoverflow를 주의해야한다!
// 가능하면 이터레이션(ex:for문)을 사용하는 것을 추천
#include <iostream>

using namespace std;

void countDown(int count);
int sumTo(int sumto);
int Fibonacci(int x, int y);

int main()
{
    countDown(5);
    cout << sumTo(10) << endl;
    Fibonacci(0, 1);
    
    return 0;
}


void countDown(int count)
{
    cout << count << endl;
    if(count > 0)
        countDown(count - 1);
}

int sumTo(int sumto)
{
    if(sumto <= 0)
        return 0;
    else if (sumto <= 1)
        return 1;
    else
        return sumTo(sumto - 1) + sumto;
}

int Fibonacci(int x, int y)
{
    cout << x + y << endl;
    if((x+y) < 10000)
        return Fibonacci(y, x+y);
    return 0;
}
// 0 1 1 2 3 5 8 13 ..
