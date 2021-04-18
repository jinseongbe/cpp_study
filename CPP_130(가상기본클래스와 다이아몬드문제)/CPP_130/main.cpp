// 다이아몬드 상속문제를 virtual function을 사용하여 해결하는 방법!

#include <iostream>

using namespace std;

class PoweredDevice
{
public:
    int m_i;
    
    PoweredDevice(int power)
    {
        cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner : virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
    : PoweredDevice(power)
    {
        cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
    : PoweredDevice(power)
    {
        cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
    : Scanner(scanner, power), Printer(printer, power),
    PoweredDevice(power)
    {}
};

int main()
{
    
    Copier cop(1, 2, 3);
    
    cout << &cop.Scanner::PoweredDevice::m_i << endl;
    cout << &cop.Printer::PoweredDevice::m_i << endl;
    return 0;
}
