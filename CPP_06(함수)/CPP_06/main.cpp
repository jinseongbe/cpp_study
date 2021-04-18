#include <iostream>

using namespace std;

int multiplyTwoNumbers(int num_a, int num_b)
{
    int sum = num_a * num_b;
    
    return sum;
}

void printHelloWorld()
{
    cout << "Hello World " << endl;
    
    return; // 빼도 상관은 없음
    
    cout << "Hello World2 " << endl; // return 때문에 생략됨
}

int main()
{
    cout << multiplyTwoNumbers(1, 2)<< endl;
    cout << multiplyTwoNumbers(3, 4)<< endl;
    cout << multiplyTwoNumbers(8, 13)<< endl;
    
    cout << "Hello World " << endl;
    printHelloWorld();
    
    
    return 0;
}
