#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date1
{
public:         //access specifier(접근지정자)
    int m_month;
    int m_day;
    int m_year;
};

class Date2 // encapsulation
{
private:         //default는 private이므로 안써줘도 자동으로 private임, 외부에서 class에 접근 할 수 없음
    int m_month;
    int m_day;
    int m_year;
    
public:
    void setDate(const int &month_input, const int &day_input, const int &year_input)
    {
        m_month = month_input;
        m_day = day_input;
        m_year = year_input;
    } // class 안에서는 private안에 내용에 접근 할 수 있음!
    
    void setMonth(const int &month_input)
    {
        m_month = month_input;
    }
    
    int getDay()
    {
        return m_day;
    }
    
    const int &getYear()
    {
        return m_year;
    }
    
    void copyFrom(const Date2 &original) // 같은 클래스에 들어있는 instance는 가져다 쓸 수 있다.
    {
        m_month = original.m_month;
        m_day = original.m_day;
        m_year = original.m_year;
    }
};


int main()
{
    Date1 today;
    today.m_month = 8;
    today.m_day = 4;
    today.m_year = 2025;
    
    Date2 today2;
//    today2.m_month = 8; // private이므로 오류남
//    today2.m_day = 4;
//    today2.m_year = 2025;
    today2.setDate(8, 4, 2025);  // private이지만 access fuction을 사용하여 수정해줄수 있음!
    
    Date2 copy;
    //copy.setDate(today.getMonth(), today.getDay(), today.getYear())
    //위처럼 일일이 복사하기는 귀찮기 때문에 데이터 복사용 함수를 class에 넣어준다.
    
    
    return 0;
}
