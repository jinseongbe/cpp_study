#include <iostream>
#include <limits>

using namespace std;

float getfloat()
{
    while(true)
    {
        cout << "Enter a number : ";
        float x;
        cin >> x;
        std::cin.ignore(3.40282e+38, '\n');
        
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(3.40282e+38, '\n');
            cout << "Invalid number, please try again" << endl;
        }
        else
        {
            std::cin.ignore(3.40282e+38, '\n');
            return x;
        }
    }
}

char getOperator()
{
    while(true)
    {
        cout << "Enter an operator (+, -, *, /) : ";
        char op;
        cin >> op;
        std::cin.ignore(3.40282e+38, '\n');
        if(op == '+' || op == '-' || op == '*' || op == '/')
            return op;
        else
            cout << "Invalid operator, please try again" << endl;
    }
}

void printResult(float x, char op, float y)
{
    if(op == '+') cout << x + y << endl;
    else if(op == '-') cout << x - y << endl;
    else if(op == '*') cout << x * y << endl;
    else if(op == '/') cout << x / y << endl;
    else
    {
//        cout << "Invalid operator" << endl;
    }
}

int main()
{
    float x = getfloat();
    char op = getOperator();
    float y = getfloat();

    printResult(x, op, y);
    
    return 0;
}
