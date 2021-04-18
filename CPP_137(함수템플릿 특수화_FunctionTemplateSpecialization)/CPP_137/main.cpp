#include "Storage.h"

using namespace std;

template<typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

template<>
char getMax(char x, char y)
{
    cout << "Warning : comparing chars" << endl;
    
    return (x > y) ? x : y;
}

//

int main()
{
    cout << getMax(1, 2) << endl << endl;
    cout << getMax('a', 'b') << endl;
    //cout << getMax<int>(1, 2) << endl; 이것과 같음!
    
    Storage<int> nValue(5);
    Storage<double> dValue(6.7);
    
    nValue.print();
    dValue.print();

    return 0;
}
