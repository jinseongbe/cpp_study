#include <iostream>
#include <array>

using namespace std;

int func();
int func2();
int func3(int x);
void printNumbers(const array<int, 10> &my_array, bool print_even);
void printNumbers_ptr(const array<int, 10> &my_array, bool (*check_fcn)(const int&));
bool isEven(const int& number);
bool isOdd(const int &number);

int main()
{
    cout << func << endl;   // 함수도 주소를 가지고 있다.
    
    int(*fcnptr)() = func;
    cout << fcnptr() << endl;
    
    fcnptr = func2;
    cout << fcnptr() << endl;
    
    
    int(*fcnptr2)(int) = func3;
    cout << fcnptr2(1) << endl;
    
    
    std::array<int, 10> my_array{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    printNumbers(my_array, 1);
    printNumbers(my_array, 0);
    
    
    printNumbers_ptr(my_array, isOdd);
    printNumbers_ptr(my_array, isEven);
    
    return 0;
}

int func()
{
    return 5;
}

int func2()
{
    return 10;
}

int func3(int x)
{
    return 10;
}

void printNumbers(const array<int, 10> &my_array, bool print_even)
{
    for(auto element : my_array)
    {
        if (print_even && element % 2 == 0) cout << element;
        if (!print_even && element % 2 == 1) cout << element;
    }
    cout << endl;
}

void printNumbers_ptr(const array<int, 10> &my_array, bool (*check_fcn)(const int&))
{
    for(auto element : my_array)
    {
        if(check_fcn(element) == true) cout << element;
    }
    cout << endl;
}

bool isEven(const int& number)
{
    if (number % 2 == 0)
        return true;
    return false;
}

bool isOdd(const int &number)
{
    if (number % 2 != 0)
        return true;
    return false;
}
