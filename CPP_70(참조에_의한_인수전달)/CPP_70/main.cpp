#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void  getSinCos(double degrees, double &sin_out, double &cos_out);
void foo(const int &x);
void foo1(int *&ptr);
void printElements1(int (&arr)[4]);
void printElements2(vector<int>&arr);

int main()
{
    double sin(0.0);
    double cos(0.0);
    getSinCos(30, sin, cos);
    cout << sin << " " << cos << endl;
    
    
    
    foo(6); // 레퍼런스는 리터럴을 받을 수 없기 때문에 - input을 사용할때 const 변수로 넣거나,
    
    cout << endl;
    
    int y = 5;
    int *ptr_y = &y;
    
    foo1(ptr_y);
    cout << ptr_y << " " << &ptr_y << endl;
    
    
    
    int arr[]{ 1, 2, 3, 4};
    vector<int> arrVec{ 1, 2, 3, 4};
    
    printElements1(arr);
    printElements2(arrVec);
    
    
    return 0;
}


void  getSinCos(const double degrees, double &sin_out, double &cos_out) // const로 안바뀌게 방지도 가능
{
    static const double pi = 3.141592 / 180.0;      // 연산을 많이 하지 않도록 static으로 사용
    
    const double radians = degrees * pi; // 한번 계산된것은 바뀌지 않도록 const를 사용 할 수도 있음!
    sin_out = std::sin(radians);
    cos_out = std::cos(radians);
}

void foo(const int &x) // const를 빼면 리터럴이라 주소가 없어서 레퍼런스로 입력이 안되는 컴파일 오류 발생함!
{                      // 이런식으로 쓰는 것이 일반적인 것임!
    cout << x << endl;
}

void foo1(int *&ptr) // const를 빼면 리터럴이라 주소가 없어서 레퍼런스로 입력이 안되는 컴파일 오류 발생함!
{                      // 이런식으로 쓰는 것이 일반적인 것임!
    cout << ptr << " " << &ptr << endl;
}

void printElements1(int (&arr)[4])   // 반드시 개수가 들어가야함! 실코드애서 이런식으로 쓰진 않음(정적보단 동적을 쓰기 때문)
{
    cout << "array" << endl;
}

void printElements2(vector<int>&arr)
{
    cout << "array_vector" << endl;
}
