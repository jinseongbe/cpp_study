#include <iostream>
#include <limits>

int main()
{
    using namespace std;
    
    char c1(65);
    char c2('A'); //한 글자를 표현할때는 따옴표, 문자열을 표현할때는 겹따옴표
    
    cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;
    
    // c-style casting
    cout << (char)65 << endl;
    cout << (int)'A' << endl;
    
    // cpp style casting
    cout << char(65) << endl;
    cout << int('A') << endl;
    
    cout << static_cast<char>(65) << endl; // statice,dynamic
    cout << static_cast<int>('A') << endl;
    
    char ch(97);
    cout << ch << endl;
    cout << static_cast<int>(ch) << endl;
    cout << ch << endl;
    
    cout << "This is first line \nsecond line\n"; // \n 그냥 줄바꿈만 하는것
    cout << "This is first line \tsecond line\n"; // \t tap
    cout << "This is first line " << endl; // endl은 버퍼에 있는 것은 다 출력하고 줄을 마쳐라 라는뜻
    cout << "second line" << endl;
    cout << "std::flush" << std::flush; // 줄바꿈은 하지 말고 버퍼에 있는것을 다 출력해라
    cout << " \" 겹따옴표 쓰려면 이렇게 \" " << endl;
    cout << " \a ";
    
    // 다른사람이 코드를 보고 이해하기 쉽도록 스테틱을 써주기도 함 눈에 확들어 오니까
    // 버퍼라는게 존재해서 문자 하나를 받는 c1에 문자열 abc를 넣어주면 차례대로 출력하게 됨
    cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;
    cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;
    cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;
    
    cout << sizeof(char) << endl;
    cout << (int)std::numeric_limits<char>::max() << endl;
    cout << (int)std::numeric_limits<char>::lowest() << endl;
    
    return 0;
}
