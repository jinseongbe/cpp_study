#include <iostream>
#include <cstddef>
#include <locale>
#include <string>

using namespace std;

int main(void)
{
    // c-style string example(실행안됨, 이유모르겠음 아직)
//    {
//        char *strHello = new char[7];
//        strcpy_s(strHello, sizeof(char) * 7, "hello!");
//        std::cout << strHello << std::endl;
//    }
    
    //basic_string<>, string, wstring
//    {
//        std::string string;
//        std::wstring wstring;
//
//        wchar_t wc;         // wide-character/unicode(unsignd char) 데이터 사이즈가 더 큰 문자열을 사용할때 사용함
//                            // 데이터가 많이 필요한 세계 여러 언어를 사용할때 주로 쓰게됨
//    }
//
    // wstring example
    
        // Stackoverflow.com
        
    const std::wstring texts[] =
    {
        L"Hello",
        L"안녕하세요",
        L"Ñá", //Spanish
        L"forêt intérêt", //French
        L"Gesäß", //German
        L"取消波蘇日奇諾", //Chinese
        L"日本人のビット", //Japanese
        L"немного русский", //Russian
        L"ένα κομμάτι της ελληνικής", // Greek
        L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
        L"کمی از ایران ", // Persian (I know it, from 300 movie)
        L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
        L"Но какво, по дяволите, е това?" //Bulgarian
    };
    
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());
    
    for (size_t i = 0; i < 11; ++i)
    {
        std::wcout << texts[i] << std::endl;
    }
    
    cout << "위에것들은 언어가 설치되어있지 않아서 실행이 안되는듯" << endl;
    
    
    return 0;
}
