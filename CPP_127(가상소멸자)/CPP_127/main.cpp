#include <iostream>

using namespace std;

class Base
{
public:
    virtual ~Base()     // virtual이 없으면 상속받은 class에서 메모리 lick이 발생함
    {                   // 즉 Derived class에 소면자 ~Derived가 호출되지 않음
        cout << "~Base()" << endl;
    }
};

class Derived : public Base
{
private:
    int *m_array;
    
public:
    Derived(int length)
    {
        m_array = new int[length];
    }
    
    virtual ~Derived() override // Base클래스에 virtual이 없으면 오류발생함(이름이 달라서), 그렇지만 있으면 작동함
    {                           // override는 써도 그만 안써도 그만. ~Derived에 virtual은 관습상 써준것! 디버깅하기 편하도록!
        cout << "~Derived()" << endl;
        delete[] m_array;
    }
};

int main()
{
//    Derived derived(5);
    
    Derived *derived = new Derived(5);
    Base * base = derived;
    delete base;
    
    // 이렇게 사용하는 것이 일반적인데, 왜냐하면 대부분으 경우 자식클래스가 많고 다양하기 때문에
    // 일일이 하나씩 지워주는것이 번거롭고 헷갈리기 때문에 부모클래스의 소멸자를 통해 지워준다!
    
    
    return 0;
}
