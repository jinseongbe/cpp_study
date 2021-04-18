#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    const char my_strs [] = "Hello, World"; // 기본적으로 사용하는 방식!: 기본 자료형
    const string my_hello1 = "Hello, World"; // 편하게 사용하도록 만든 방법: 일종의 사용자 정의 자료형
    const string my_hello2("Hello, World");
    const string my_hello3{ "Hello, World" };
    /*
    cout << my_strs << endl;
    cout << my_hello1 << endl;
    cout << my_hello2 << endl;
    cout << my_hello3 << endl;
    */
    string my_ID;
    string my_password;
    
    
    cout << "Your ID?: ";
//    cin >> my_ID;                 // 띄어쓰기를 하면 입력이 끊기는 문제가 있음
//    std::getline(std::cin, my_ID);  // 한줄을 통으로 받아서 띄어쓰기 해도 문제 없음!
    
    int number;
    cin >>number; // 버퍼에 숫자가 남아서 작동 오류남
    std::cin.ignore(32767, '\n'); // 최대 32767개의 글자를 잊어버려라(버퍼에담지말고),
    // 코드애 32767 r같은 숫자를 두고 싶지 않을때
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "Your pasrrword?: ";
//    cin >> my_password;
    std::getline(std::cin, my_password);
    cout << endl;
    
    cout << "ID\t\t: " << my_ID << endl;
    cout << "Password: " << my_password << endl << endl;;
    
    
    string a("hello ");
    string b("world");
    string hw = a + b; //append, sring class안에 정의가 되어있어서 사용 가능한것임!
    
    hw += " I'm good";
    
    cout << hw << endl;
    cout << a.length() << endl;
    
    
    
    
    
    
    return 0;
}
