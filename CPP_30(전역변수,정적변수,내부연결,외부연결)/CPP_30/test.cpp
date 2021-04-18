#include <iostream>
#include "MyConstant.h"

extern int A(123);

void dododo()
{
    using namespace std;
    cout << "In test.cpp file pi " << Constants::pi << endl;
    cout << "In test.cpp file pi address" << &Constants::pi << endl;
}
