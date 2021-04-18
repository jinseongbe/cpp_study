#include <iostream>
#include <string>

using namespace std;

int main()
{
    // syntax errors - 문법 오류(;같은것 빼먹은 경우)
    
    // semantic errors - 문맥 오류
    int x;
    cin >> x;
    if(x >= 5)  // 이상과 초과 등등 문맥상의 오류
        cout << "x is greater than 5" << endl;
    
    // violated assumption - 가정을 위반했다(사용자가 작성한방식이랑 완전 다른 방식으로 사용한다)
    string hello = "Hello, my name is jack";
    int ix;
    cin >> ix;
    cout << hello[ix] << endl;  // 사용자가 글자수보다 넘은 값을 넣으면 런타임 에러 발생함!
    
    // 이런 오류를 방지하기 위한 것들을 해야함!
    string hello2 = "Hello, my name is jack";
    
    while(1)
    {
        int ix2;
        cin >> ix2;
        
        if(ix2 >= 0 && ix2 <= hello.size() - 1)
        {
            cout << hello2[ix2] << endl;
            break;
        }
            
        else
            cout << "Please try again" << endl;
    }
    
    
    return 0;
}
