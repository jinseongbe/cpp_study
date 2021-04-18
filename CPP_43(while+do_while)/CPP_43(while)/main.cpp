#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    
    while (count < 100)
    {
        cout << count << endl;
        ++count;
        
        if (count == 57) break;
    } //굳이 안에서 변수를 선언하고 싶다면 static을 사용하면 된다! static int count = 0;
    
    
//    unsigned int countt = 10;
//    while (countt >= 0)
//    {
//        if (countt == 0) cout << "zero";
//        else cout << countt << "    ";
//
//        countt--; // unsigned 변수를 사용했을때 감소하는 경우 오버플로우 문제가 발생한다!!
//    }
    
    int num = 0;
    
    while(num <= 100)
    {
        if(num % 5 == 0) cout << "Hello " << num << endl;
        num++;
    }
    
    
    int outer_count = 1;
    while(outer_count <= 5)
    {
        int inner_count = 1;
        while (inner_count <= outer_count)
        {
            cout << inner_count++ << " ";
        }
        cout << endl;
        outer_count++;
    }
    
    // do while
    
    int selection; // must be declared outsidde do/while loop
    
    do
    {
        cout << "1. add" << endl;
        cout << "2. sub" << endl;
        cout << "3. mult" << endl;
        cout << "4. div" << endl;
        cin  >> selection;
    } while (selection <= 0 || selection >= 5);
    
    cout << "Your selected " << selection << endl;
    
    return 0;
}
