#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void goodbye(const string & s)
{
    cout << "Goodbye " << s << endl;
}

class Object
{
public:
    void hello(const string & s)
    {
        cout << "Hello " << s << endl;
    }
};

// lambda : anonymous function이라고도 불림(익명함수)
int main()
{
//    lambda-introducer : []
//    lambda-parameter-declaration : (const int& i)
//    lambda-return-type-clause : -> void 뒤에서 리턴타입을 정해주는 방식
//    compound-statement
    auto func = [](const int& i) -> void { cout << "Hello, World!" << endl; };
    
    func(123);
    
    [](const int& i) -> void { cout << "Hello, World!" << endl; } (12342);   // 이렇게 바로 사용가능! lambda function의 진정한 가치
    
    {
        string name = "JackJack";
        [&]() {std:cout << name << endl; } ();
//        [&name]() {std:cout << name << endl; } ();
//        [this]() {std:cout << name << endl; } (); // class의 member를 정의할때
//        [=]() {std:cout << name << endl; } ();    // name을 copy해서 넣어주는 방식
    }
    
    
    
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    
    auto func2 = [](int val) { cout << val << endl; };
    for_each(v.begin(), v.end(), func2);    // <algorithm>
    // lambda function은 사실 위에서 처럼 쓰기보단 아래와 같이 사용한다.(선호한다)
    for_each(v.begin(), v.end(), [](int val) { cout << val << endl; });    // <algorithm>
    
    
    
    cout << []() -> int { return 1; }() << endl;
    
    
    
    std::function <void(int)> func3 = func2;
    func3(123);
    
    // 특정파라미터에 맞추기 귀찮다면 아래의 bind를 사용
    std::function<void()>func4 = std::bind(func3, 456);
    // = std::function<void(void)>func4 = std::bind(func3, 456);
    func4();
    
    // https://en.cppreference.com/w/cpp/utility/functional/placeholders
    {
        Object instance;
        auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);
        
        f(string("World"));
        // == f("World"); // 이렇게만 해도 실행됨
        
        auto f2 = std::bind(&goodbye, std::placeholders::_1);
        
        f2(string("World"));
    }
    
    
    
    return 0;
}
