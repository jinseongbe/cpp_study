#include <iostream>
#include <tuple>

using namespace std;

// 고전적 방법
tuple<int, int> my_func()
{
    return tuple<int, int> (123, 456);
}

// 다른 방법 1
auto my_func2()
{
    return tuple<int, int> (123, 456);
}

// c++ 17의 현대적 방법
auto my_func3()
{
    return tuple(123, 456, 789);
}


int main()
{
    // 1.
    tuple<int, int> result = my_func();
    cout << get<0>(result) << " " << get<1>(result) << endl;
    
    // 2.
    auto result2 = my_func2();
    cout << get<0>(result2) << " " << get<1>(result2) << endl;
    
    // 3.
    auto result3 = my_func3();
    cout << get<0>(result3) << " " << get<1>(result3) << " " << get<2>(result3) << endl;
    
    auto [a, b, c] = my_func3();
    cout << a << " " << b << " " << c << endl;

    return 0;
}
