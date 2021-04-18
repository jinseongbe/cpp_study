#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int  m_id;
    string      m_name;
    
public:
    Student(const string &name_in)      // 아이디넘버는 따로 받기위해 이런식으로 추가적인 생성자를 만드는 것은 매우 안좋음!
    : m_id(0)                           // 프로그래밍을 할때는 같은 기능을 하는 것을 두개 이상 만들면 매우 안좋음!
    , m_name(name_in)                   // 즉 아래 이름을 대입해주는 것이 있기 때문에 추가로 만들면 이름 대입 기능이 2가지가
    // :Student(0, name_in)*            // 돼서 나중에 프로그래밍할때 문제가 많이 발생 할 수 있음
    {}                                  // 띠리사 셍상지기 셍상자를 사용 할 수 있기 때문에 그 방법*을 이용한다!
                                        // 이것이 위임생성자임!(cpp11 이상부터 가능)
    Student(const int &id_in, const string &name_in)
    : m_id(id_in)
    , m_name(name_in)
    {}
    
    void print()
    {
        cout << m_id << " " << m_name << endl;
    }
};

// 위임생성자가 생기기 이전의 코딩 스타일! 이 방법이 더 좋은것 같음! 필요할때 이것으로 쓸것!
// 만능함수를 만들어서 그 함수를 불러다 사용하는 방식임
class Student2
{
private:
    int  m_id;
    string      m_name;
    
public:
    Student2(const string &name_in)
    {
        init(0, name_in);
    }
                                        
    Student2(const int &id_in, const string &name_in)
    {
        init(id_in, name_in);
    }
    
    void init(const int &id_in, const string &name_in)
    {
        m_id    = id_in;
        m_name  = name_in;
    }
    
    void print()
    {
        cout << m_id << " " << m_name << endl;
    }
};


int main()
{
    Student st1(0 , "jackjack");
    st1.print();
    
    return 0;
}
