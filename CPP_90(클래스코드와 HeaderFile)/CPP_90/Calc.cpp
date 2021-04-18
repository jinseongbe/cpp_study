#include "Calc.h"

using namespace std;        // cpp 파일에 있는 것은 큰 문제가 되지 않으니
                            // 헤더파일에 넣지 말고 여기에 넣어주자!
void Calc::add(int value)
{
    m_value += value;
}

void Calc::sub(int value)
{
    m_value -= value;
}

void Calc::mult(int value)
{
    m_value *= value;
}

void Calc::print()
{
    cout << m_value << endl;
}

Calc::Calc(int int_value)
: m_value(int_value)
{}

