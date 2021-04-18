#include <iostream>

using namespace std;

class Exception
{
public:
    void report()
    {
        cerr << "Exception report" << endl;
    }
};

class ArrayException : public Exception
{
public:
    void report()
    {
        cerr << "Array exception" << endl;
    }
};


class MyArray
{
private:
    int m_data[5];
    
public:
    int &operator [] (const int & index)
    {
//        if (index < 0 || index >= 5) throw -1;
//        if (index < 0 || index >= 5) throw Exception();
        if (index < 0 || index >= 5) throw ArrayException();
        
        return m_data[index];
    }
};


void doSomething()
{
    MyArray my_array;
    
    try
    {
        my_array[100];
    }
    catch (const int &x)
    {
        cerr << "Excoption" << x << endl;
    }
    catch (ArrayException &e)
    {
        cout << "doSomething()" << endl;
        e.report();
        
        // rethrow : 바깥쪽에서(main)에서도 error를 받아주기 위해 사용함
        throw e;
        
    }
    catch (Exception &e)
    {
        cout << "doSomething()" << endl;
        e.report();
        throw;
    }
//    catch (ArrayException &e)   // 부모클래스가 먼져 오류를 잡아서 실행이 안되는 것임!
//    {                           // 해결법 : 순서를 바꿔준다!
//        cout << "doSomething()" << endl;
//        e.report();
//    }
}


int main()
{
    
    try
    {
        doSomething();
    }
    catch (ArrayException &e)   // 안에서 이미 에러르 catch했기 떄문에  이 부분은 실행 되지 않음
    {
        cout << "main()" << endl;
        e.report();
    }
    
    
    return 0;
}
