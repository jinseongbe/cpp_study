#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printCharacterClassification(const int & i)
{
    cout << boolalpha;
    cout << "isalnum " << bool(std::isalnum(i)) << endl;    // integer값으로 return 해줌
    cout << "isblack " << bool(std::isblank(i)) << endl;    // 맨 아래에 사용법 있음(단일항목의 blank에 대해서 찾아줌)
    cout << "isdigit " << bool(std::isdigit(i)) << endl;
    cout << "islower " << bool(std::islower(i)) << endl;
    cout << "isupper " << bool(std::isupper(i)) << endl;
}

void printStates(const std::ios& stream)
{
    cout << boolalpha;
    cout << "good()=" << stream.good() << endl;     // bool값으로 return 해줌
    cout << "eof()="  << stream.eof()  << endl;
    cout << "fail()=" << stream.fail() << endl;
    cout << "bad()="  << stream.bad()  << endl;
}

bool isAllDigit(const string &str)
{
    bool ok_flag = true;
    
    for (auto e : str)
    {
        if (!std::isdigit(e))
        {
            ok_flag = false;
            break;
        }
    }
    return ok_flag;
}

void classifyCharacters(const string &str)
{
    for (auto e : str)
    {
        cout << e << endl;
        std::cout << "isdigit " << std::isdigit(e) << endl;
        std::cout << "isblank " << std::isblank(e) << endl;
        std::cout << "isalpha " << std::isalpha(e) << endl;
    }
}


int main()
{
    
    while (true)
    {
//        int i;
        char i;
        cin >> i;
        
        printStates(cin);
        
        cout << i << endl;
        
        // ios에 들어있는 라이브러리를 사용하지 않고 직접하는 경우( 퍼포먼스가 조금 더 빠룰수도 있고 아닐 수도 있다)! == printStates(cin)
        cout << boolalpha;
        cout << std::bitset<8>(cin.rdstate()) << endl;
        cout << std::bitset<8>(std::istream::goodbit) << endl;
        cout << std::bitset<8>(std::istream::failbit) << endl;
        cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;
        
        printCharacterClassification(i);
        
        cin.clear();
        cin.ignore(1024, '\n');
        cout << endl;
    }
    
    
    cout << boolalpha;
    cout << isAllDigit("1234") << endl;
    cout << isAllDigit("a1234") << endl;
    
    classifyCharacters("1234");
    classifyCharacters("a 1234");
    
    
    // regular expression 사용하는게 훨씬 편함 (점점 사용하는 추세, 더 편리함 - 다음강의)
    
    return 0;
}
