#pragma once

#include <iostream>

template<class T>
class AutoPtr
{
private:
    T* m_ptr;
    
public:
    AutoPtr(T* ptr = nullptr)
    : m_ptr(ptr)
    {
        std::cout << "AutoPtr default constructor " << std::endl;
    }
    
    ~AutoPtr()
    {
        std::cout << "AutoPtr destructor " << std::endl;
        
        if(m_ptr != nullptr) delete m_ptr;
    }
    
    AutoPtr(const AutoPtr& a)
    {
        std::cout << "AutoPtr copy constructor " << std::endl;
        
        // deep copy
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }
    
    AutoPtr & operator = (const AutoPtr &a)
    {
        std::cout << "AutoPtr copy assignment " << std::endl;
        
        if(&a == this)      // prevent self-assignment
            return *this;
        
        if(m_ptr != nullptr) delete m_ptr;
        
        // deep copy
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
        
        return *this;
    }
    
    
    // 아래부터는 move임!
    
    AutoPtr(AutoPtr &&a)
    : m_ptr(a.m_ptr)
    {
        a.m_ptr = nullptr; // really necessary? 강의하시는 분은 깔끔하게 코딩하기 위해서는 이렇게 하는게 좋다고 말씀하심
        
        std::cout << "AutoPtr move constructor " << std::endl;
    }
    
    AutoPtr & operator = (AutoPtr &&a)
    {
        std::cout << "AutoPtr move assignment " << std::endl;
        
        if (&a == this)      //prevent self-assignment
            return *this;
        
        if (!m_ptr) delete m_ptr;
        
        // shallow copy
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;  // really necessary?
        
        return *this;
    }
    
};
