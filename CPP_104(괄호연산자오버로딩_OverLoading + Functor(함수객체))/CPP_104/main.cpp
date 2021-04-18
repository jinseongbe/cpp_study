#include <iostream>

using namespace std;

class Accumulator
{
private:
    int m_counter = 0;
    
public:
    int operator () (int i) { return (m_counter += i); }
};

int main()
{
    Accumulator acc;
    cout << acc(10) << endl;    // 이런식으로 class를 마치 함수 모양으로 사용하는것을
    cout << acc(20) << endl;    // Function object (functor, 함수객체)라고 부른다
                                // 재미있게 사용 가능할지도?
    return 0;
}


