#include <iostream>
#include <string>
#include <vector>
#include <sstream>  // string stream

using namespace std;

template <typename T>
std::string ToString(T x)
{
    std::ostringstream osstream;
    
    osstream << x;
    return osstream.str();   // 들어온걸 뭐가 되었든 string으로 만들어줌
}

template <typename T>
bool FromString(const std::string & str, T
                
                &x)
{
    std::istringstream isstream(str);
    return (isstream >> x) ? true : false;
}


int main()
{
    std::string my_string1;
    cout << my_string1 << endl;  // default 생성자라 아무것도 안뜸
    
    
    std::string my_string2("my string");
    cout << my_string2 << endl;
    
    
    std::string my_string3(my_string2);
    cout << my_string3 << endl;
    
    
    std::string my_string4(my_string2, 3);
    cout << my_string4 << endl;     // 이건 앞에서 3개를 지우고 저장
    
    
    std::string my_string5(my_string2, 3, 5);
    cout << my_string5 << endl;
    
    
    const char *my_string6 = "my string";
    cout << my_string6 << endl;
    
    
    std::string my_string7(my_string6, 4);
    cout << my_string7 << endl;     // 이건 앞에서 4개까지만 제거하고 저장
    
    
    std::string my_string8(10, 'A');
    cout << my_string8 << endl;
    
    
    std::vector<char> vec;
    for (auto e : "Today is a good day.")
        vec.push_back(e);
    
    std::string my_string9(vec.begin(), vec.end());
    cout << my_string9 << endl;
    
    std::string my_string10(vec.begin(), std::find(vec.begin(), vec.end(), 'y'));
    cout << my_string10 << endl;
    
    
    std::string my_str1(std::to_string(1004));
    cout << my_str1 << endl;
    
    my_str1 += std::to_string(128);
    cout << my_str1 << endl;
    
    int i = std::stoi(my_str1);
    cout << i << endl;
    
    int f = std::stof(my_str1);
    cout << f << endl;
    
    
    std::string my_str2(ToString(3.141592));
    cout << my_str2 << endl;
    
    double d;
    if(FromString(my_str2, d))
        cout << d << endl;
    else
        cout << "Cannot convert string to double" << endl;
    
    
    std::string my_str3("Hello");
    
    if(FromString(my_str3, d))
        cout << d << endl;
    else
        cout << "Cannot convert string to double" << endl;

    return 0;
}


