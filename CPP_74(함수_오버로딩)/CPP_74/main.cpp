// 함수 오버로딩: 동일한 이름을 가지는 함수를 여러개 만드는 것

#include <iostream>
#include <string>

using namespace std;
typedef int my_int;

//void print(int x) {}
//void print(my_int x) {} // typedef를 사용해도 같은 매개변수가 int로 인식되어 함수오버로딩이 되지 않는다!

int add(int x, int y);
int add(double x, double y);

int main()
{
    add(1, 2);
    add(1.0, 3.4);
    // 컴파일러가 함수에 들어가는 매개변수가 가장 적절한것을 찾아 함수를 사용한다.
    // 어떤 함수를 사용할지는 컴파일 할때 결정되어야 한다!!
    // 또한 함수 이름이 같은데 매개변수도 같을 경우 오류가 난다! 즉 이름이 같더라도 매개변수는 무조건 달라야 한다!
    
    return 0;
}


int add(int x, int y)
{
    return x + y;
}

int add(double x, double y)
{
    return x + y;
}


