#include <iostream>
#include <typeinfo>

int add(int a, int b)
{
    return a + b;
}

auto add_auto(int a, int b) // 함수를 정의할때도 추론 가능함!
{
    return a + b;
}

auto add_trailling(int x, int y) -> int // int add(int x, int y)랑 같은 의미, 보기 좋게 정리하려고 사용함
{
    return x + y;
}

int main()
{
    using namespace std;
    
    int a = 123; //사실 이 자료가 정수라는 것은 중복되는 내용 따라서 auto로 교체 가능
    auto b = 123; // 형 추론, auto keyword 따라서 초기화 하지 않으면 사용 불가
    auto c = 123.0;
    auto d = 1 + 2;
    auto e = 1 + 2.0;
    
    cout << "a : " << typeid(a).name() << endl;
    cout << "b : " << typeid(b).name() << endl;
    cout << "c : " << typeid(c).name() << endl;
    cout << "d : " << typeid(d).name() << endl;
    cout << "e : " << typeid(e).name() << endl;
    
    
    auto result = add(1, 2); // 함수의 결과도 자동으로 형을 결정 할 수 있음
    
    
    
    
    return 0;
}
