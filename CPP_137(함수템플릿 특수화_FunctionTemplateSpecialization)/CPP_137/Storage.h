#pragma once
#include <iostream>

template <class T>
class Storage
{
private:
    T m_value;
    
public:
    Storage(T value)
    {
        m_value = value;
    }
    
    ~Storage()
    {
    }
    
    void print()
    {
        std::cout << m_value << '\n';
    }
};

// 이것을 cpp 파일로 definition을 빼고 굳이 싶다면, cpp파일을 main.cpp에 직접 include하는 방법도 있음(비추!)
template<>
void Storage<double>::print()
{
    std::cout << "Douvle Type ";
    std::cout << std::scientific << m_value << '\n';
}
