#include <iostream>

using namespace std;

void breakOrReturn()
{
    while (true)
    {
        char ch;
        cin >> ch;
        
        if (ch == 'b')
            break;
        
        if (ch == 'r')
            return;
            }
    cout << "Hello" << endl;
}

int main()
{
//    breakOrReturn();
    
    for (int i = 0; i < 10; ++i)
    {
        cout << i << endl;
        if (i == 5) break;
    }
    cout << endl << endl;
    
    // continue
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0) continue; // 조건을 만족해서 continue가 실행되면 아래를 실행하지 않고 다시 위로 반복문을 돈다
        
        cout << i << endl;
    }
    cout << endl << endl;
    
    
    int count(0);
    do
    {
        if (count == 5)
            continue;
        
        cout << count << endl;
    } while (++count < 10); // 무한루프를 방지하기 위해 증감연산자를 while안에 넣어줬다
    cout << endl << endl;
    
    
    int countt(0);
    bool escape_flag = false;
    while (!escape_flag)
    {
        char ch; // 변수는 복잡해질수록 밖에 빼주는게 효율적이다!
        cin >> ch;
        
        cout << ch << " " << countt++ << endl;
        
        if (ch == 'x')
            escape_flag = true;
    }
    
    int countt2(0);
    while (true)
    {
        char ch; // 변수는 복잡해질수록 밖에 빼주는게 효율적이다!
        cin >> ch;

        cout << ch << " " << countt2 << endl;

        if (ch == 'x')
            break;
    }

    
    
    
    return 0;
}
