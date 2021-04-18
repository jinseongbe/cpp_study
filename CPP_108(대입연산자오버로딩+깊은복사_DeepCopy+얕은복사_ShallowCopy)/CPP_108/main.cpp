#include <iostream>
//#include <cassert>

using namespace std;

class MyString
{
//private:
public:
    char *m_data = nullptr;                     // 1.default copy = 그냥 변수들을 그대로 복사해서 넣어준다!
    int m_length = 0;                           //   (shallow copy) 문제점은 동적할당의 경우 주소를 그대로 복사해서 넘겨주기때문에, 복사해서 생긴 class에서
                                                //      (얕은 복사)    new, delete 중 값이 사라져버리는데, 그걸 그대로 사용하게 될 수도 있다!!
public:                                         //                  즉 두개의 class가 같은 주소의 값을 사용하다 보니 문제가 발생하는것!
    MyString(const char *source = "")
    {
        assert(source);
        
        m_length = std::strlen(source) + 1; // 문자열의 마지막이라는 null이라는 값을 넣기 위한 공간으로 +1
        m_data = new char[m_length];
        
        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];
        
        m_data[m_length - 1] = '\0';
    }
    
    MyString(const MyString &source)            // 2.default copy의 문제점을 해결하기 위해 만들어준것
    {                                           // = 복사한 class에서 다시 동적할당을 해줘서(새로운주소를 부여) 내용을 복사하여 넣어준다.
        cout << "Copy constructor " << endl;    // (deep copy)(깊은 복사)
        
        m_length = source.m_length;
        
        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];
            for(int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
    }
    
    // copy construct를 사용할 여유가 없을때 차선책으로 사용 할 수 있는 방법 : 복사가 안되게 막는방법임!!
    // MyString(const MyString &source) = delete;
    
    MyString &operator = (const MyString &source)
    {
        // if shallow copy(default copy)
        // this->m_data = source.m_data;
        // this->m_length = source.m_length;
        
        cout << "Assignment operator " << endl;
        
        if (this == &source) // prevent self-assignment : 자기가 자신에게 복사되는 문제를 방지하기 위함
            return *this;    // 넣어준것과 주소가 같은면 그냥 자기 자신을 return하고 끝내도록 하는것!
        
        delete[] m_data;
        
        m_length = source.m_length;
        if(source.m_data != nullptr)
        {
            m_data = new char[m_length];
        }
        
        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];
            for(int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;

        return *this;
    }
    
    
    
    ~MyString()
    {
        delete[] m_data;
    }
    
    char* getString() { return m_data; }
    int getLine() { return m_length; }
};



int main()
{
    MyString hello("Hello");
    
    cout << (int*)hello.m_data << endl;     // (int*)가 없으면 문자열로 인식하기 때문에 int로 강제 형변환해준것임 - 주소를 보기위해
    cout << hello.getString() << endl;
    cout << endl;
    
    // scope
    {
        MyString  copy = hello;
        cout << (int*)copy.m_data << endl;
        cout << copy.getString() << endl;
    }
    
    cout << hello.getString() << endl;
    
    cout << endl << endl;
    
    // copy constructor가 호출되는 경우와 assignment로 복사되는 경우의 차이점!!
    
    MyString str1 = hello;  // '='가 쓰였지만 copy constructor가 사용되고 있다! 정의되는 부분이기 때문에
                            // MyString str1(hello); 이런식으로 사용하면 덜 헷갈리게 만들수있다!
    MyString str2;
    str2 = hello;
    
    cout << endl;
    
    
    // 결론 이렇게 만들기 힘드니까 그냥 std::string을 사용하라 그럼 모든 문제 해결됨
    // 다만 퍼포먼스가 조금 떨어질순 있으나 사실 잘만 하면 큰 문제는 없음
    // 최근 언어는 string을 사용하는 법을 주로 알려주나, 본질적인 문제가 무엇인지 아는것이 중요함!

    return 0;
}
