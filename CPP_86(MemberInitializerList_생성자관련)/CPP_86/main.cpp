#include <iostream>

using namespace std;

class B
{
private:
    int m_b;
    
public:
    B(const int &m_b_in)
    : m_b(m_b_in)
    {}
};

class Something
{
private:
    int     m_i;
    double  m_d;
    char    m_c;
    int     m_arr[5];   //cpp11이상부터 가능
    B       m_b;

public:
    Something()     // initialize : {}같은 경우는 형변환이 안되기 때문에 더 엄격함!
    : m_i(1)
    , m_d(3.14)
    , m_c{ 'a' }
    , m_arr{ 1, 2, 3, 4, 5}
    , m_b(m_i - 1)
    {
        //m_i = 1;
        //m_d = 3.14;
        //m_c = 'a';
    }
    
    void print()
    {
        cout << m_i << " " << m_d << " " << m_c << endl;
        for (auto &e : m_arr)
            cout << e << " ";
        cout << endl;
    }
};

class Something2
{
private:
    int     m_i = 2;    // 생성자로 정의한것이 우선임
    double  m_d = 4;
    char    m_c = 19;
    B       m_b = 20;

public:
    Something2()        // 생성자가 더 우선순위가 높다!
    : m_i(1)
    , m_d(3.14)
    , m_c{ 'a' }
    , m_b(m_i - 1)
    {
        m_i = 10;         // 아래에서 넣어주면 위에 생성자를 실행하고 그 다음에 실행되는 것임
        m_d *= 3.14;     // 위에 initialize가 무시되는 것이 아님! 실행되고 그 다음음 실행!
        m_c += 3;
        m_b = m_i - 10;
    }
    
    void print()
    {
        cout << m_i << " " << m_d << " " << m_c << endl;
        cout << endl;
    }
};

int main()
{
    Something sme;
    sme.print();
    
    Something2 sme2;
    sme2.print();
    
    return 0;
}
