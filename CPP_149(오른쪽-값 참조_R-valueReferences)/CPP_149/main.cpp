#include <iostream>

using namespace std;

void doSomething(int &lref)
{
    cout << "L-value ref" << endl;
}

void doSomething(int &&ref)
{
    cout << "R-value ref" << endl;
}

int getResult()
{
    return 100*100;
}


int main()
{
    int x = 5;
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();
    
    // L-value references
    
    int &lr1 = x;           // Modifiable l-values
    //int &lr2 = cx;        // Non-modifiable l-value
    //int &lr3 = 5;         // R-value
    
    const int &lr4 = x;     // Modifiable l-values
    const int &lr5 = cx;    // Non-modifiable l-values
    const int &lr6 = 5;     // R-values
    
    
    // R-value references
    
    //int &&rr1 = x;        // Modifiable l-values
    //int &&rr2 = cx;       // Non-modifiable l-values
    int &&rr3 = 5;          // R-values
    
    cout << rr3 << endl;
    rr3 = 10;
    cout << rr3 << endl;
    
    //const int &&rr4 = x;  // Modifiable l-values
    //const int &&rr5 = cx; // Non-modifiable l-values
    const int &&rr6 = 5;    // R-valuse
    
    
    
    // L/R-value reference parameters
    doSomething(x);
    //doSomething(cx);
    doSomething(5);
    doSomething(getResult());
    
    return 0;
}
