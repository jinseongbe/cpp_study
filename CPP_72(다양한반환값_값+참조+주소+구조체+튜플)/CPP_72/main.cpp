#include <iostream>
#include <array>
#include <tuple>

using namespace std;

int getValue1(int x);
int* getValue2(int x);
int& getValue3(int x);
int& get(std::array<int, 100>& my_array, int ix);

std::tuple<int, double> getTuple()
{
    int a = 10;
    double d = 3.14;
    return std::make_tuple(a, d);
}

struct S
{
    int a, b, c, d;
};

S getStruct()
{
    S my_s {100, 22, 31, 43};
    return my_s;
}

int main()
{
    // 값으로 반환(return by value)
    int value1 = getValue1(10);      // 간결하고 좋지만, 복사가 많이 일어나 퍼포먼스가 느림!
    cout << value1 << endl;
    cout << endl;
    
    // 주소로 반환(return by address)
    int value2_1 = *getValue2(10);   // 권장하는 방법은 아님! 사라질 변수를 dereference하는 것이기 때문에
    cout << value2_1 << endl;
    int *value2_2 = getValue2(10);   // 위의 것보다 더 위험한 방법!!
    cout << *value2_2 << endl;
    cout << endl;
    
    // 참조로 반환(return by reference)
    int value3 = getValue3(20);
    cout << value3 << endl;
    int &value3_1 = getValue3(10);   // 레퍼런스로 받으면 위험함! 함수안에서 레퍼런스는 사라지는 값이기 때문에!
    cout << value3_1 << endl;
    cout << value3_1 << endl;        // 일시적으로 잡아놓은 주소값이 사라져서 쓰레기 값이 출력됨!
    cout << endl;
    
    std::array<int, 100> my_array;   // 이런 패턴으로 참조로 반환하는 것을 자주 사용함!
    my_array[30] = 10;               // 메모리는 처음에 잡아두고, 변수처럼 바꿔 사용하는 방식!
    cout << my_array[30] << endl;
    get(my_array, 30) = 1024;
    cout << my_array[30] << endl;
    cout << endl;
    
    // 구조체로 반환(옛날 라이브러리가 이렇게 되어 있는 경우가 있음), c-style 코딩(속도는 좀 더 빠름)
    S my_s = getStruct();
    cout << my_s.a << endl;
    cout << my_s.b << endl;
    cout << endl;
    
    // 튜플로 반환
    std::tuple<int, double> my_tp = getTuple();     // cpp 17 미만 버전
    cout << std::get<0>(my_tp) << endl;     // a
    cout << std::get<1>(my_tp) << endl;     // b
    
    auto[a, d] = getTuple();                        // cpp 17 이상 버전
    cout << a << endl;
    cout << d << endl;
    
    return 0;
}

int getValue1(int x)
{
    int value = x * 2;
    return value;
}

int* getValue2(int x)
{
    int value = x * 2;
    return &value;
}

int& getValue3(int x)
{
    int value = x * 2;
    return value;
}

int& get(std::array<int, 100>& my_array, int ix)
{
    return my_array[ix];
}

