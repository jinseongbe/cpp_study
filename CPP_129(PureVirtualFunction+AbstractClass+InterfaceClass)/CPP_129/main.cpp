#include <iostream>
#include <string>

using namespace std;

// 1. pure virtual function
class Animal
{
protected:
    string m_name;
    
public:
    Animal(std::string name)
    : m_name(name)
    {}
    
public:
    string getName() { return m_name; }
    
    virtual void speak() const = 0;     // pure virtual function
    
    /*
    virtual void speak() const
    {
        cout << m_name << " ??? " << endl;
    }
    */
};

//void Animal::speak() const  // pure virtual function도 바디를 만들 순 있지만 호출 할 수 없음(즉 쓸데없음)
//{
//    cout << m_name << " ??? " << endl;
//}

class Cat : public Animal
{
public:
    Cat(string name)
    : Animal(name)
    {}
    
    void speak() const
    {
        cout << m_name << " Meow " << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name)
    : Animal(name)
    {}
    
    void speak() const
    {
        cout << m_name << " Woof " << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(string name)
    : Animal(name)
    {}
};


// 2. Interface Class : pure virtual function만으로 만들어진 class
class IErrorLog         // 관습적으로 Interface를 구현할때는 대문자 I를 붙여줌
{
public:
    virtual bool reportError(const char *errorMessage) = 0;
    
    virtual ~IErrorLog() {}
};

class FileErrorLog  : public IErrorLog
{
public:
    bool reportError(const char *errorMessage) override
    {
        cout << "Writing error to a file" << endl;
        return true;
    }   // 소멸자는 defualt 소멸자를 알아서 만들어준다!
};

class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char *errorMessage) override
    {
        cout << "Printing error to a console" << endl;
        return true;
    }
};

void doSomething(IErrorLog &log)
{
    log.reportError("Runtime error!!");
}


int main()
{
    // 1. pure virtual function
//    Animal animal("hi");  // pure virtual function은 바디를 만들수 없음!
                            // 즉 부모클래스에서는 이 함수에 대해 모른다! 그러니
                            // 자식함수에서 꼭 구현하라, 만들어라 라는 뜻
    
    Dog dog("jackjack");
    dog.speak();
//    Cow cow("hello");     // Cow는 pure virtual function을 오버라이드 해주지 않았기 때문에 오류발생함!
                            
    // abstract class : puref virtual function을 하나라도 포함하는 클래스
    
    cout << endl << endl;
    
    // 2. Interface Class
    
    FileErrorLog file_log;
    ConsoleErrorLog console_log;
    
    doSomething(file_log);
    doSomething(console_log);
    
    return 0;
}
