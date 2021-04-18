#include <iostream>
#include <string>

using namespace std;

class Something
{
public:
    Something(const Something &st_in)   // A1: 기본적으로 이런 생성자가 숨겨서 내장되어있음, 사용자가 변경 가능!
    {                                   // 이런것을 Copy Constructor 라고 부름.
        m_value = st_in.m_value;
        cout << "Copy Construct" << endl;
    }
    
    Something()
    {
        cout << "Constructor " << endl;
    }
    
    int m_value = 0;
    
    void setValue(int value) { m_value = value; }
    int  getValue() const    // int  getValue() const : 뒤에 const를 붙이면 Member Fuction를 const로 만들어줌
    {
        return m_value;
    }
};

void print(Something st)
{
    cout << &st << endl;
    cout << st.getValue() << endl;
}

void print2(const Something &st)        // 이 경우는 복사 없이 바로 가져 쓰는것이기 때문에 가장 최적화한것임
{
    cout << &st << endl;
    cout << st.getValue() << endl;
}

class Something2
{
public:
    string m_value = "default";
        
    string &getValue()
    {
        cout << "non-const version" << endl;
        return m_value;
    }
    
    const string &getValue() const  // 일반적으로 내부 fuction을 const로 만들기 위해서 return도 const로 해줌!
    {
        cout << "const version" << endl;
        return m_value;
    }
};



int main()
{
//    const Something some1;
//    //some1.setValue(3);      // class 내부에 있는것을 바꿀 수 없기 때문에 오류발생!
//    cout << some1.getValue() << endl;   // class 내부에 있는것을 바꾸려는 것은 아니지만
//    cout << endl << endl;               // Member Function이 const인지 아닌지로 판다하기 때문에 오류발생함!
//                                        // 여기서 함수 뒤에 const 붙이면 오류 해결 가능!
//                                        // 그러나 setValue와 같이 바꾸려는 함수에는 const를 붙여도 오류남(문맥상)!!
//                              //중요: const로 만들수있는 함수는 모두 const로 만들어주는게 좋음! 디버깅에도 유리, 실수적게
    
    Something some2;
    print(some2);
    cout << &some2 << " " << endl;  // Q1.원래 함수라고 하면 복사가 되어서 Class가 두번 사용되어서 Constructor가
    cout << endl << endl;           // 두번 출력되어야 될 것 같은데 한번 출력되는 이유는?
    
    Something some3;                // print2 함수에서 const + & 로 보내주면 주소가 같음!
    print2(some3);
    cout << &some3 << " " << endl;
    cout << endl << endl;
    
    
    // const를 사용하는 오버로딩 방식! 재밌음!
    Something2 someST1;
    someST1.getValue() = 20;        // 본인이 const가 아니기 때문에 non-const가 출력됨
    
    const Something2 someST2;
    someST2.getValue();             // 본인이 const이기 때문에 const 버전이 출력됨, 즉 바꿀수 없음
    
    
    return 0;
}
