#include "MyArray.h"
//#include "MyArray.cpp"  // 가급적으로 이런식으로 링킹에러를 해결하지 마라!!!

using namespace std;

int main()
{
    MyArray<double> my_array(10);
//    MyArray<int> my_array(10);
//    MyArray<char> my_array(10);
    
    for (int i = 0; i < my_array.getLength(); ++i)
        my_array[i] = i * 0.5;
    
    my_array.print();
    
    return 0;
}
