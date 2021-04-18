#pragma once

#include <iostream>

class Cents
{
private:
    int m_cents;
    
public:
    Cents(int cents)
    : m_cents(cents)
    {}
    
    // 템플릿으로 만든것을 사용할때는 그와 관련된 기능등을 다 만들어줘야한다!
    friend bool operator > (const Cents &c1, const Cents &c2)
    {
        return(c1.m_cents > c2.m_cents);
    }
    
    friend std::ostream &operator << (std::ostream & out, const Cents &cents)
    {
        out <<  cents.m_cents << " cents ";
        return out;
    }
    
};
