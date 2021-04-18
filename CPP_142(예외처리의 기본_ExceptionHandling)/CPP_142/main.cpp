#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int findFirstChar(const char *string, char ch)
{
    for (std::size_t index = 0; index < strlen(string); ++index)
    {
        if (string[index] == ch)
            return index;
    }
    
    return -1; // no match
}

double divide(int x, int y, bool &success)
{
    if (y == 0)
    {
        success = false;
        return 0.0;
    }
    
    success = false;
    return static_cast<double>(x) / y;
}

int main()
{
    // 전통적인 방식의 예외처리 방법
    // 지저분해 보이지만 계속 써오는 이유!
    // 1. 퍼포먼스 측면
    // 2. 다른 대체 할 수 있는 문법이 마땅치 않았기 때문에
    // 예외처리는 퍼포먼스를 낮추기 때문에 큼직큼직하게 사용하는 것이 좋다!
    bool success;
    double result = divide(5, 3, success);
    
    if (!success)
        std::cerr << "An error occurred" << std::endl;
    else
        std::cout << "Result is " << result << std::endl;
    
    std::ifstream input_file("temp.txt");
    if (!input_file)
        std::cerr << "Cannot open file" << std::endl;
    cout << endl;
    
    
    // 현대적인 방식의 예외처리 방법(전통적인 예외처리방법을 대체 하기 위해 만들어 진것아 아님을 명심!)
    // try, catch, throw
    
    double x(-1);
    
    
    try
    {
        if (x < 0.0) throw std::string("Negative input");   // throw와 catch에서 받아주는 것은 엄격하게 형태를 맞춰줘야한다(형변화 자동x)
        
        cout << std::sqrt(x) << endl;
    }
    catch (std::string error_message)
    {
        // do something to respond
        cout << error_message << endl;
    }
    
    try
    {
        // something happend
//        throw -1;
//        throw std::string("My error");
        throw "My error";
    }
    catch (int x)
    {
        cout << "Catch integer" << x << endl;
    }
    catch (double x)
    {
        cout << "Catch Double" << x << endl;
    }
    catch (const char * error_message)
    {
        cout << "Char * " << error_message << endl;
    }
    catch (std::string error_message)
    {
        cout << error_message << endl;
    }
    
    return 0;
}
