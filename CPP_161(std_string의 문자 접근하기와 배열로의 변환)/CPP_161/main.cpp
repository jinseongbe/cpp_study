#include <iostream>
#include <string>

using namespace std;

int main()
{
    string my_str("abcdefg");
    
    cout << my_str[0] << endl;
    cout << my_str[3] << endl;
    
    my_str[3] = 'Z';
    cout << my_str << endl;
    
    
    
    try
    {
        
        //my_str[100] = 'X';// 강의에서는 런타임 에러가 발생하는데
                            // 여기서는 안발생함..?
                            // 일단 발생한다는 가정하에, try안에서는 느려지니까
                            // try안에서는 []영역에 대해서는 에러를 잡아주지 않는다고 함
                            // 그래서 사용하려면 아래와 같이 쓰라고 알려줌!
        
        my_str.at(100) = 'X';   // 이떄는 런타임 에러 잡아줌..(근데 왜 위에서는 오류가 안뜨는지..?)
                                // 이렇게 사용하면 []보다 퍼포먼스는 떨어짐, 상황따라 판단할것
                            
    }
    catch (std::exception & e)
    {
        cout << e.what() << endl;
    }
    
    // c-style로 출력하기!
    cout << my_str.c_str() << endl;
    // 이때 주의할것은 아래 순서!
    cout << (int)my_str.c_str()[6] << endl;
    cout << (int)my_str.c_str()[7] << endl;
    // stirng자체에는 null character가 저장되지 않지만
    // c-style로 가져올때는 null을 뒤에 붙여줌, 진짜 c-style로 만들어 주는거임
    
    // 비슷한걸로 std::data가 있음(거의 같다, 똑같다)
    
    // c-style로 복사하는 법
    char buf[20];
    
    my_str.copy(buf, 5, 0); // 5글자복사, 오프셋은 0
                            // 복사는 해주지만 null character는 넣어주지 않는다.
    cout << buf << endl;
    
    buf[5] = '\0';          // 그래서 직접 넣어줌
    
    cout << buf << endl;
    
    return 0;
}
