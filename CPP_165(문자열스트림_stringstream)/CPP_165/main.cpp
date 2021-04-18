#include <iostream>
#include <sstream> // string stream

using namespace std;

int main()
{
    stringstream os;
    
    os << "Hello, world!";      // << : insertion operator, >> : extraction operator
    os.str("Hello, World!\n");    // 이건 전부(통채로) 넣는 것이고 위의 인설션 오퍼레이터는 추가해주는 방식이다.
    // stringstream 안에 \n, endl등을 넣을 수 있다.
    
    string str;
    os >> str;  //  빈칸은 짤림
    cout << str << endl;
    
    str = os.str();
    cout << str << endl;
    
    cout << endl;
    
    stringstream os2;
    os2 << "Hello" << endl;
    os2 << "Nop!";
    
    string str2;
    str2 = os2.str();
    cout << str2 << endl;
    
    
    
    stringstream os3;
    
    os3 << "12345 53.64";       // 빈칸을 기준으로 나눠서 들어간다.
    
    string str3;
    string str4;
    
    os3 >> str3 >> str4;
    
    cout << str3 << "|" << str4 << endl;
    
    
    
    stringstream os4;
    
    int i = 11234;
    double d = 67.89;
    
    os4 << i << " " << d;
    
    os4 >> str3 >> str4;
    cout << str3 << "||" << str4 << endl;
    

    
    stringstream os5;
    os5 << i << " " << d;
    int i2;
    double d2;
    
    os5 >> i2 >> d2;

    cout << i2 << " " << d2 << endl;
    
    
    
    os5.str("");
    os5.clear();    // clear : state까지 초기화 함!
    cout << os5.str() << endl;
    
    
    
    return 0;
}
