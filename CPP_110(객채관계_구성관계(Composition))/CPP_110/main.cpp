#include "monster.h"

using namespace std;

int main()
{
    Monster mon1("Sanson", Position2D(0, 0));
    cout << mon1 << endl;
    
    Monster mon2("Parsival", Position2D(0, 0));

//    Monster안에 쓰여진 Position2D는 Composition으로 각자 구성관계이다.
//    mon1.m_location;
//    mon2.m_location;
    
    {
        mon1.moveTo(Position2D(1, 1));
        cout << mon1 << endl;
    }
    
    return 0;
}
