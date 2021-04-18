#include <iostream>

using namespace std;


class Simple
{
private:
    int m_id;
    
public:
    Simple(const int &id_in)
    : m_id(id_in)
    {
        cout << "Constructor " << m_id << endl;
    }
    
    ~Simple()
    {
        cout << "Destructor " << m_id << endl;
    }
};

class IntArray
{
private:
    int *m_arr = nullptr;   // delete을 쓰는것이 불안하면 vector를 사용: vector안에 이러한 매커니즘이 실현되어있음!
    int m_length = 0;       // 또한 그 뿐 아니라 만들어 쓰면 new,delete가 작동하면서 느려지는 것이 생기니
                            // 퍼포먼스를 생각한다면 vector를 사용하면됨(vector는 크기를 정해놓는거 기억하기!)
public:
    IntArray(const int length_in)
    {
        m_length = length_in;
        m_arr = new int[m_length];
        cout << "Constructor " << endl;
    }
    
    ~IntArray() // 소멸자를 사용하지 않으면 메모리 누수 발생!(memory leak)
    {
        if(m_arr != nullptr)
            delete [] m_arr;
    }
    int size() { return m_length; }
};


int main()
{
    Simple s1(0);
    Simple s2(1);
    Simple *s3 = new Simple(3);
    
    delete s3;
    /* [보충] 소멸자는 instance가 메모리에서 해제될 때 내부에서 자동으로 호출된다.
        동적할당으로 만들어진 경우에는 영역을 벗어나도 자동으로 메모리가 해제되지 않기 떄문에
        delete로 메모리를 해제할 때에만 소멸자가 호출된다.
        소멸자를 프로그래머가 직접 호출하는 것은 대부분의 경우 권장되지 않는다. */
    
    while(1)
    {
        IntArray my_int_arr(10000);
    }

    return 0;
}
