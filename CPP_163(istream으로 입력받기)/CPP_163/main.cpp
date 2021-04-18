#include <iostream>
#include <string>
#include <iomanip> // input,output manipulators

using namespace std;

int main()
{
    // 1. buf
    char buf[5];   // 10글자 짜리 char
    cin >> buf;
    cout << buf << endl; // 10글자가 넘어가면 runtime error 발생
    
    // 2. setw()
    char buf2[5];
    cin >> setw(5) >> buf2;
    cout << buf2 << endl;   // 4글자 출력됨, 한자리는 null pointer

    cin >> setw(5) >> buf2; // 추가적으로 입력받지 않아도 다음 나올 문자를 buf2에서 불러서 출력함
    cout << buf2 << endl;

    cin >> setw(5) >> buf2;
    cout << buf2 << endl;
    
    
    // 3. cin.get()
    char ch;
    while (cin >> ch)   // 빈칸은 없어짐!
        cout << ch;

    char ch2;

    while(cin.get(ch2))     // 이경우에는 빈칸까지 출력 가능
        cout << ch2;

    
    // 이런경우에는 빈칸으로 구분하여 입력 받을 수 있기 때문에 좋게 사용 될 수 도 있다
    int i;
    float f;
    cin >> i >> f;
    cout << i << " " << f << endl;
    
    
    // 4. cin.get(), cin.gcount
    char buf4[5];
    cin.get(buf4, 5);
    cout << cin.gcount() << " " << buf4 << endl;

    cin.get(buf4, 5);   // 뺀것을 제외하고 나머지부터 다시 가져옴
    cout << cin.gcount() << " " << buf4 << endl;

    
    // 5. cin.getline()
    char buf5[10];
    cin.getline(buf5, 10);
    cout << cin.gcount() << " " << buf5 << endl;

    cin.getline(buf5, 10);   // getline은 줄을 통제로 가져오기 떄문에 get과 다르게 뒤에 있는것이 마져 가져와지지 않음
    cout << cin.gcount() << " " << buf5 << endl; // 또한 getline은 뒤에 줄바꿈기호 '\n' 도 포함하기 때문에 글자수가 1개 더 많ㅇ다

    
    // 6. string buf
    string buf6;    // 동적 array로 buf를 받아 올 수 있음 이게 더 편리함
    getline(cin, buf6);
    cout << cin.gcount() << " " << buf6 << endl;    // cin으로 get한게 아니므로 gcount는 0이 나온다!
    

    // 7. cin.ignore()
    char buf7[1024];
    cin.ignore();
    //cin.ignore(2);   // 한글자를 무시함 '()'안에 숫자를 넣으면 그 숫자만큼의 글자를 무시함
    cin >> buf7;
    cout << buf7 << endl;
    
    
    // 8. cin.peek()
    char buf8[1024];
    cout << (char)cin.peek() << endl;   // buf에서 들여다보는것, 실제로 꺼내지는 않음! 즉 사용 후에도 buf에 글자가 남아있음

    cin >> buf8;
    cout << buf8 << endl;
    
    
    // 9. cin.unget();
    char buf9[1024];
    cin >> buf9;
    cout << buf9 << endl;
    
    cin.unget();    // 마지막으로 읽은것을 다시 buf로 되돌려주는 기능
    
    cin >> buf9;
    cout << buf9 << endl;
    
    
    // 10. cin.putback()
    char buf10[1024];
    cin >> buf10;
    cout << buf10 << endl;
    
    cin.putback('A');   // 원하느 글자를 buf에 다시 넣어주는 기능!
    
    cin >> buf10;
    cout << buf10 << endl;

    
    return 0;
}
