#include <iostream>

bool isEqual(int a, int b)
{
    bool result = (a == b);
    return result;
}


int main()
{
    using namespace  std;
    
    bool b1 = true; //copy initialization
    bool b2(false); // direct initialization
    bool b3{ true }; // uniform initialization
    b3 = false;
    
    cout << std::boolalpha; // 출력을 true false 로 바꿔서 해줌
    cout << !true << endl; // 출력은 반대로 !==not 연산자
    cout << !b3 << endl;
    cout << endl;
    
    cout << (true && true) << endl; //둘다 참이여야 참
    cout << (true && false) << endl;
    cout << (false && true) << endl;
    cout << (false && false) << endl;
    cout << endl;
    
    cout << (true || true) << endl; // 둘중 하나라도 참이면 참
    cout << (true || false) << endl;
    cout << (false || true) << endl;
    cout << (false || false) << endl;
    cout << endl;
    
    if (false)
        cout << "This is true" << endl; //한줄까진 중괄호 안써줘도 됨
    else
    {
        cout << "This is false" << endl; //두줄이상부턴 중괄호 필요
    }
    cout << endl;
    
    cout << isEqual(1, 1) << endl;
    cout << isEqual(1, 4) << endl;
    
    if (1)
        cout << "if는 0이 아니면 모두 true 로 판단" << endl;
    cout << endl;
    
    // 0을 입력해야 false임
    bool x;
    cout << "입력하세요 : ";
    cin >> x;
    cout << "Your in put : " << x << endl;
    
    return 0;
}
