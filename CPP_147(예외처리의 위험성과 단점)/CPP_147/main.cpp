#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
    ~A()    // 금기시 되는일! 소멸자 안에서 throw를 사용하고 있음!!
    {       // distructor에서는 throw를 사용하는 것이 금지되어있음! 그러나 실행은 되기 때문에 주의!
        throw "error";
    }
};

int main()
{
    
    try
    {   // 1
        // 만약 메모리를 할당하는 부분에서 error가 발생할경우
        // 메모리를 삭제하지 못해서 메모리 누수가 발생 할 수 있음!
        int *i = new int[1000000];
        unique_ptr<int> up_i(i);    // 유니크 포인트가 알아서 메모리를 지워줌(스마트포인터)
                                    // throw가 되어도 지워준다!
        
        
        // do something with i
        throw "error";
        
        // unique_ptr을 사용 할 경우 아래 delete는 필요가 없다!
//        delete[] i;
        
        
        // 2 (주의해야할점!)
        //A a;
    }
    catch(...)
    {
        cout << "Catch" << endl;
    }
    return 0;
}
        // 추가적으로 빈번하게 사용되는 for문 안에서 try를 사용하는것은 퍼포먼스(속도)를 아주 저하 시킬수있다! 주의하자!
