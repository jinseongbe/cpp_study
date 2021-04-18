#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception
{
public:
    const char *what() const noexcept override  // noexcept : cpp +11 이상부터는 넣어줘야 한다!(적어도 이 안에서는 오류를 던지지 않겠다라는 뜻)
    {
        return "Custom exception";
    }
};


using namespace std;

int main()
{
    try
    {
        // 1
//        std::string s;
//        s.resize(-1);   // 내부에서 throw가 구현되어 있음
        
        // 2
//        throw std::runtime_error("Bad thing happened");   // 직접 출력도 가능
        
        // 3
        throw CustomException();    // 직접 exception class를 만들때는 중요한 합수인 what()을 만들어주자!
    }
    catch(std::length_error &exception)
    {
        std::cerr << "Length_Error" << std::endl;
        std::cerr << exception.what() << std::endl;
    }
    catch(std::exception &exception)
    {
        std::cout << typeid(exception).name() << std::endl; // exception class 안에서 정확히 뭔 오류인지 알려줌
        std::cerr << exception.what() << std::endl;     // what
    }
    return 0;
}
