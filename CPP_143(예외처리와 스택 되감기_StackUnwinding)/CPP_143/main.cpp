#include <iostream>

using namespace std;

void first();
void second();
void third();
//void last();

//void last() throw(int) exception specifier
//void last() throw(...) exception specifier

void last() throw(int)          // int 타입의 에러를 throw 할 수 도 있다라는 뜻
{                               // 이것은 불필요한것이 아니냐고 하는 견해가 많다고함!
                                // 마이크로소프트 비쥬얼스튜디오 문서에 따르면 throw()안에 뭘 넣어도 된다고함
                                // throw(...)로 받아들여진다고함, 주의할것은 파라미터가 없으면("throw()") 예외를 안던진다는 뜻이 됨!
    cout << "last " << endl;    // 완전이 상반된 의미가 됨으로 주의할것, 보통은 잘 사용 안한다고함!
    cout << "Throws exception" << endl;
    
    throw 'a';
    
    cout << "End Last" << endl;
}

int main()
{
    cout << "Start" << endl;
    
    try
    {
        first();
    }
    catch (int)
    {
        // cerr : c error (cout과 다르게 바로바로 버퍼를 안통하고 출력함!)
        // clog : c log
        // cout : c out (버퍼에 담기고 바로바로 출력 안하는 경우도 있음)
        // 이 3가지의 기능상 큰 차이 없지만, 출력하는 채널이 다르다 쯤으로 이해하면됨
        
        cerr << "main caught int exception" << endl;
    }
    // uncaught exceptions(예상 할 수 없는 나머지 에러)
    catch (...) // catch-all handlers "..."(ellipses) : 다 받아준다는 뜻!
    {
      cerr << "main caught ellipses exception" << endl;
    }
    
    cout << "End main" << endl;
    
    return 0;
}

void first()
{
    cout << "first" << endl;
    
    try
    {
        second();
    }
    catch (char)
    {
        cerr << "first caught int exceotion" << endl;
    }
    
    cout << "End first" << endl;
}

void second()
{
    cout << "second" << endl;
    
    try
    {
        third();
    }
    catch (double)
    {
        cerr << "Second caught double exception" << endl;
    }
    
    // throw -1 일때 이 부분이 실행되지 않고 first함수로 올라감! 포인트!
    cout << "End second " << endl;
}

void third()
{
    cout << "third" << endl;
    
    last();
    
    // 못잡아서 실행 안됨!
    cout << "End third" <<endl;
}

void last()
{
    cout << "last " << endl;
    cout << "Throws exception" << endl;
    
//    throw -1;
//    throw 'c';
//    throw -1.0;
    throw "string";

    
    cout << "End last " << endl;    // 실행안됨! throw에서 바로 catch를 찾으러 감
}
