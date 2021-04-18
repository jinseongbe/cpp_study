#include <iostream>

using namespace std;

class Digit
{
private:
    int m_digit;
    
public:
    Digit(int digit = 0) : m_digit(digit) {}
    
    // prefix (전위형)
    Digit & operator ++ ()
    {
        ++m_digit;
        cout << "*this :" << *this << endl;
        return *this;   // return m_digit
    }
    
    // postfix (후위형) : 주의점!!! 전위형과 후위형을 구분해주기위해 후위형에는 파라미터를 넣어서 다르게 해준다!!!
    Digit operator ++ (int)
    {
        Digit temp(m_digit);
        
        ++(*this);
        
        return temp;
    }
    friend ostream & operator << (ostream &out, const Digit &d)
    {
        out << d.m_digit;
        return out;
    }
};

int main()
{
    Digit d(10);
    
    cout << ++d << endl;
    cout << d   << endl;
    
    cout << d++ << endl;
    cout << d   << endl;
    return 0;
}
