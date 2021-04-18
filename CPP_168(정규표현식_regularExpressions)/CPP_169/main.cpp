#include <iostream>
#include <regex>        // cpp11 이상

using namespace std;

int main()
{
//    regex re("\\d");            // \d : \한개는 뒤의 \가 진짜라는 뜻, \d = 숫자인지 판별하는 의미, 여기서는 숫자 한개를 의미함
//    regex re("\\d*");           // * : 한개 이상의 문자를 받아도 되고 아예 안받아도 상관없음!
//    regex re("\\d+");           // + : 한개 이상의 숫자를 받아도 된다 대신 아무것도 안받으면 NoMatch
//    regex re("[ab]");           // a와 b만 가능( 문자 한개 )
//    regex re("[[:digit:]]{3}"); // [:digit:] == \d 와 같은 기능임, backSlash가 거슬리면 사용하면 됨
//                                // {number} : number수 만큼의 글자를 입력받겠다.
//    regex re("[A-Z]+");
//    regex re("[A-Z]{1,5}");     // 최소 1개 최대 5개
    regex re("([0-9]{1})([-]?)([0-9]{1,4})");       // [-]? : '-'가 있어도 되고 없어도 된다는 뜻, ?가 있든 없든을 의미
    
    string str;
    
    while (true)
    {
        getline(cin, str);
        
        if (std::regex_match(str, re))
            cout << "Match" << endl;
        else
            cout << "No match" << endl;
        
        // print matches
        {
            auto begin = std::sregex_iterator(str.begin(), str.end(), re);
            auto end = std::sregex_iterator();
            for (auto itr = begin; itr != end; ++itr)
            {
                std::smatch match = *itr;
                cout << match.str() << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    
    return 0;
}
