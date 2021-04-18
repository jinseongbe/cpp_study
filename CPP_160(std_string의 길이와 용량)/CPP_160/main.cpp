#include <iostream>
#include <string>

using namespace std;

int main()
{
    string my_str("012345678");
    cout << my_str.size()       << endl;    // <- 주의할점! c-style의 문자열에서는 마지막에 null 값을 포함해서 한글자가 더 많은 크기를 가지지만
                                            //    string의 경우는 class로써 내부적으로 포인터 말고 길이를 직접 가지고 있기 때문에 null값을 찾을 필요가 없어서 없음
    cout << my_str.capacity()   << endl;    // <- new,delete할 시간을 줄이기 위해, 여분의 용량을 가지고 있는것! (reallocate를 줄이기 위함)
    cout << my_str.max_size()   << endl;
    
    my_str.reserve(1000);                   // <- 최소한 이만큼의 크기는 확보해달라는 뜻, 실제는 이것보다 클 수 있음
    cout << my_str.capacity()   << endl;
    
    
    
    cout << std::boolalpha;                 // <- 0, 1을 False, True로 출력
    cout << my_str.empty() << endl;         // <- 비어있냐?
    
    string my_str2;
    string my_str3("");
    cout << my_str2.empty() << endl;
    cout << my_str3.empty() << endl;    // null값을 보관하지 않음!
    
    return 0;
}
