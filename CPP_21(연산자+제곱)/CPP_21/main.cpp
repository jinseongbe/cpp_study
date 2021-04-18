#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x = 4 + 2 * 3;
    
    int y = std::pow(2, 3); // c++에서는 제곱을 이렇게 쓰고, double형태로 계산된다!
                            // ^이 c언어에서는 제곱이 아니라는 것을 명심해야함
    cout << y << endl;
    
    return 0;
}
