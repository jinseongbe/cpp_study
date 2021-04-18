#pragma once

#include <iostream>

class Calc
{
private:
    int m_value;
    
public:
    Calc(int int_value);
    
    void add(int value);
    void sub(int value);
    void mult(int value);
    void print();
};
