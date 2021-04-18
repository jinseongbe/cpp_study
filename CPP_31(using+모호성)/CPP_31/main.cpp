#include <iostream>

namespace a
{
    int my_var(20);
    int my_a(123);
    int count(123123123);
}

namespace b
{
    int my_var(10);
    int my_b(321);
}

namespace c
{
    int my_var(30);
    int my_c(456);
}

int main()
{
    using namespace std;
//    using std::cout; // 원하는 것만 namespace에서 꺼내 사용 할 수 도 있음
//    using std::endl; // 그러나 대부분의 경우서는 전ㅊ체를 불러서 사용하는 경우가 많음
    using namespace a;
    using namespace b;
    
    cout << my_a << endl;
    cout << my_b << endl;
    cout << a::my_var << endl;
    cout << b::my_var << endl;
    cout << a::count << endl;
    
    {
        using namespace c;
        //cout << my_var << endl; // 밖에 using 문에서도 영향을 받기 때문에 밖에 using을 다 빼줘야 사용 가능!
        // using은 전역에서 사용하는 것은 지양하는게 좋다! 적은 범위에서 사용하도록!
    }
        
    return 0;
}
