#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Cents
{
private:
    int m_cents;
    
public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int &getCents() {return m_cents; }
    
    friend bool operator == (const Cents &c1, const Cents &c2)
    {
        return c1.m_cents == c2.m_cents;
    }
    
    friend std::ostream &operator << (std::ostream &out, const Cents &cents)
    {
        out << cents.m_cents;
        return out;
    }
    
    friend bool operator < (const Cents &c1, const Cents &c2)       // 크기비교연산자는 왼쪽이 더 작은것으로 사용해야한다!('>'는 작동안함! 오류발생)
    {
        return c1.m_cents < c2.m_cents;
    }
};


int main()
{
    Cents cents1(6);
    Cents cents2(0);
    
    if( cents1 == cents2)
    {
        cout << "Equal " << endl;
    }
    
    cout << std::boolalpha;
    
    
    
    vector<Cents> arr(20);
    for (unsigned i = 0; i < 20; ++i)
        arr[i].getCents() = i;
    
    std::random_shuffle(begin(arr), end(arr));
    
    for (auto &e : arr)
        cout << e << " ";
    cout << endl;
    
    std::sort(begin(arr), end(arr));
    
    for (auto &e : arr)
        cout << e << " ";
    cout << endl;
    
    
    return 0;
}

