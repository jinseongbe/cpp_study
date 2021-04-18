#pragma once

#include <iostream>

// std::auto_ptr 이 있음, 예제수준에서 비슷하게 만드는 것임
// std::auto_ptr : c++ 98, 부터 들어와 있었고, c++ 17 부터는 사용하지 않기로 하였다!
// 다른것들을 사용하라!

template<class T>
class AutoPtr
{
public:
    T *m_ptr = nullptr;
    
public:
    AutoPtr(T *ptr = nullptr)
    : m_ptr(ptr)
    {
    }
    
    ~AutoPtr()
    {
        if(m_ptr != nullptr) delete m_ptr;
    }
    
    // main에서 발생하는 문제에 대한 해결책
    // 1.
    AutoPtr(AutoPtr &a)
    {
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
    }
    
    // 2. 소유권을 넘겨줌(이전) : move semantics
    AutoPtr &operator = (AutoPtr &a)
    {
        if (&a == this)
            return *this;
        
        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }
    
    // syntax vs. semantics
    // syntax : 문법에 맞냐 안맞냐, 컴파일이 되냐 안되냐
    // semantics : 컴파일이 되는건 똑같은데, 내부적으로 의미가 어떻게 되냐
    
    
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const {return m_ptr == nullptr; }
};
