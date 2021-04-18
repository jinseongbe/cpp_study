#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
        
    // find max value
    int max_number = std::numeric_limits<int>::lowest();
    for(const auto &n : fibonacci)
    {
        max_number = std::max(max_number ,n);
    }
        
    // change array values
    for(auto &number : fibonacci)
    {
         number *= 10;
    }

    
    // out put
    for(const auto number : fibonacci) // const를 써서 출력하기만 할 뿐 값을 바꾸지 않음을 명시해줌!
    {
        cout << number << " ";
    }
    
    cout << endl;
    
    return 0;
}
