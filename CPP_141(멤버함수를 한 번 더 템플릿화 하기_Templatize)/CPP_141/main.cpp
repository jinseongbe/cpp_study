#include <iostream>

using namespace std;

template<class T>
class A
{
private:
    T m_value;
    
public:
    A(const T &input)
    : m_value(input)
    {
    }
    
    // TT는 doSomething 함수 안에서만 작동한다.
    template<typename TT>
    void doSomething(const TT &input)
    {
        cout << typeid(T).name() << " " << typeid(TT).name() << endl;
        // casting에 사용되는 경우
        cout << (TT)m_value << endl;
    }

    // 입력받지 않고 사용하는 경우
//    template<typename TT>
//    void doSomething()
//    {
//        cout << typeid(T).name() << " " << typeid(TT).name() << endl;
//    }
    
    
    void print()
    {
        cout << m_value << endl;
    }
};


int main()
{
    A<int> a_int(116);
    a_int.print();
    
    a_int.doSomething('a');
    
// 입력받지 않고 사용하는 경우
//    a_int.doSomething<char>();
    
    return 0;
}
