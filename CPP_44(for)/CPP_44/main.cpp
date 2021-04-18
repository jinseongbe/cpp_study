#include <iostream>

using namespace std;

int pow(int base, int exponent)
{
    int result = 1;
    
    for (int count = 0; count < exponent; ++count)
    {
        result *= base;
    }
    
    return result;
}


int main()
{
    for (int count = 0; count < 10; ++count) // iteration: 반복
    {
        cout << count << endl;
    }// 이 상태에서는 count 변수가 for문이 끝났을때 사라진다
    
    cout << endl << endl;
    
    int count2 = 0;
    for (; count2 < 10; ++count2) // iteration: 반복
    {
        cout << count2 << endl;
    }// 이 경우에는 선언된 변수가 사라지지 않고 계속 사용 가능
    
    cout << count2 << endl << endl;
    
    
    // 무한루프
//    for(;;++count2) // == for(; true; ++ count2)
//    {
//        cout << count2 << endl;
//    }
    
    cout << pow(2, 4) << endl << endl;
    
    
    for (int countt = 9; countt >= 0; countt -= 2)
    {
        cout << countt << endl;
    }
    cout << endl << endl;
    
    for (int i = 0, j = 0; i < 10; ++i, --j)
    {
        cout << i << " " << j << endl;
    }
    cout << endl << endl;
    
    for (int i = 0, j = 0; (i + j) < 50; ++i, j += 2)
    {
        cout << i << " " << j << endl;
    }
    cout << endl << endl;
    
    
    for(int j = 0; j < 9; ++j)
        for(int i = 0; i < 9; ++i)
        {
            cout << i << " " << j << endl;
        }
    cout << endl << endl;
    
    
//    for (unsigned int i = 9; i >= 0; --i)
//        cout << i << endl; // overflow 발생! 주의할것
        
    return 0;
}
