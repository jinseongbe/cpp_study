#include <iostream>

using namespace std;

class A
{
public:
//    1. override
//    virtual void print(int x) { cout << "A" << endl; }
    
//    2. final
//    virtual void print() { cout << "A" << endl; }
    
//    3. covariant return, (공변 반환형)
    void print() { cout << "A" << endl; }
    virtual A* getThis() { return this; }
};

class B : public A
{
public:
//    1. override
//    void print(short x) override { cout << "B" << endl; }       // override : 이 함수는 오버라이드 되어야 한다고 말해주는것!
//    void print(short x) const override { cout << "B" << endl; }               오버라이드 되지 않으면 컴파일 오류 발생, 사전에 오류 발생 방지!

//    2. final
//    void print() final { cout << "B" << endl; }                 // final : 이 함수는 더이상 오버라이딩 하지 마라! 하면 오류 발생(C에서 사용x)
    
//    3. covariant return, (공변 반환형)
    void print() { cout << "B" << endl; }
    virtual B* getThis() { return this; }
};


//    2. final
//class C : public B
//{
//public:
//    virtual void print() { cout << "C" << endl; }
//};


int main()
{
    A a;
    B b;
//    C c;
    
    A &ref = b;
    b.getThis()->print();
    ref.getThis()->print();
    
    cout << typeid(b.getThis()).name() << endl;
    cout << typeid(ref.getThis()).name() << endl;
    
    
    return 0;
}
