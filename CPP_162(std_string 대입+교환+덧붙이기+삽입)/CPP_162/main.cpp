#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1("one");
    
    string str2;
    str2 = str1;
    str2 = "two";
    str2.assign("two");     // assign 함수는 자기 자신을 return함
    cout << str2 << endl;
    
    str1 = str2 + "Six!";
    cout << str1 << endl;
    
    str1.push_back('h');    // 문자는 vector처럼 push가능!
    cout << str1 << endl;
    
    str2.assign("two").append("Three").append("Four");
    str2 += "Five";         // append와 같은 역할을 함
    cout << str2 << endl;
    
    string str3("aaaa");
    str3.insert(2, "bbb");
    cout << str3 << endl;
    
    
    // swap
    string string1("one");
    string string2("two");
    cout << string1 << " " << string2 << endl;
    
    std::swap(string1, string2);
    cout << string1 << " " << string2 << endl;
    
    string1.swap(string2);
    cout << string1 << " " << string2 << endl;
    
    return 0;
}
