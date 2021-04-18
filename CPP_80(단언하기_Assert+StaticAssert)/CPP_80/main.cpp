#include <iostream>
#include <cassert>      // assert.h
#include <array>
// assert : 런타임중에 생기는 오류를 찾아서 알려주고, 어디인지 알려줌!
using namespace std;
void printValue(const array<int, 5> &my_array, const int &ix);


int main()
{
    const int number = 5;
    assert(number == 5);
    
    std::array<int, 5> my_array{ 1, 2, 3, 4, 5 };
    
    cout << my_array[5] << endl;
    
    printValue(my_array, 100);
    
    
    
    // static_assert
    const int y = 5;            // static_assert는 변수일때는 작동 암함! + 메세지를 남길수있음
    static_assert(y == 5, "x should be 5");
    
    
    return 0;
}


void printValue(const array<int, 5> &my_array, const int &ix)
{
    assert(ix >= 0);
    assert(ix <= my_array.size() - 1);
    
    cout << my_array[ix] << endl;
}
