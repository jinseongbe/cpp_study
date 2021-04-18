#include <iostream>
#include <vector>
#include <utility>      // std::forward

using namespace std;

struct MyStruct
{};

void func(MyStruct &s)
{
    cout << "Pass by L-ref" << endl;
}

void func(MyStruct &&s)
{
    cout << "Pass by R-ref" << endl;
}

//void func(MyStruct s)
//{
//    cout << "Pass by Value" << endl;
//}


template<typename T>
void func_wrapper(T t)
{
    func(t);
}


template<typename TT>
void func_wrapper2(TT&& t)
{
    func(std::forward<TT>(t));
}




int main()
{
    MyStruct s;
    
    func(s);
    func(MyStruct());
    
    cout << endl;

    // L-value 인지 R-value인지의 정보가 탬플릿되면서 사라져 버림
    func_wrapper(s);
    func_wrapper(MyStruct());

    cout << endl;
    
    
    // forward 사용시 (std::forward의 역할은 들어오는 값이 L-value이면 L값을 R-value이면 R값을 return해주는 역할을 함
    func_wrapper2(s);
    func_wrapper2(MyStruct());

    
    return 0;
}
