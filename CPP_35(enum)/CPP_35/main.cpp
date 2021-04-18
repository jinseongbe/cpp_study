#include <iostream>
#include <typeinfo>

enum Color // user-defined data types
{
    COLOR_BLACK,    // == 0
    COLOR_RED,      // == 1
    COLOR_BLUE,     // == 2
    COLOR_GREEN,    // == 3
    // 마지막에 세미콜론이 있어도 되고 없어도 작동됨!
};

enum Feeling
{
    HAPPY = -5,
    BLUE = 7,
    JOY,
    SAD,// 만약 위의 color가 BLUE였으면 컴파일이 되지 않음!
};

int main()
{
    using namespace std;
    
    Color paint = COLOR_BLACK;
    Color house(COLOR_BLUE);
    Color apple{ COLOR_RED }; // 유니폼이너셜라이제이션은 위에 초기화 한것과 특성이 조금 다름! 주의할것!
    
    cout << COLOR_BLACK << endl;
    cout << COLOR_RED << endl;
    cout << COLOR_BLUE << endl;
    cout << COLOR_GREEN << endl;
    cout << HAPPY << endl;
    cout << BLUE << endl;
    cout << JOY << endl;
    cout << SAD << endl;
    
    return 0;
}
