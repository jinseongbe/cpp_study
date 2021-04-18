#include <iostream>

using namespace std;

int generateID()        // 고유 넘버를 부여할때 쓰는 예제중 하나
{
    static int s_id = 0;
    return ++s_id;
}


class Something1        // 정적(static)멤버 변수는 아래와 같이 선언해줘야 한다!
{
public:
    static int s_value;
};

 
int Something1::s_value = 10;   // 헤더로 분리할때 정적변수선언은 cpp파일에 넣어줘야 오류가 발생하지 않는다!!!
                                // define in cpp!!! : 중복선언의 문제발생(정의는 한곳에만 있어야한다!)


class Something2        // 정적(static)멤버 변수는 아래와 같이 선언해줘야 한다!
{
public:
    static const int ss_value = 100;
};

//Something2::ss_value = 10;  // const 변수이기 때문에 값을 바꿔줄수없다!

int main()
{
    cout << generateID() << endl;
    cout << generateID() << endl;
    cout << generateID() << endl;
    cout << endl << endl;
    
    
    
    // 정적멤버변수
    
    cout << &Something1::s_value << " " << Something1::s_value << endl;
    
    Something1 st1;
    st1.s_value = 2;
    
    Something1 st2;
    
    cout << &st1.s_value << " " << st1.s_value << endl;
    cout << &st2.s_value << " " << st2.s_value << endl;
    
    Something1::s_value = 1024;
    cout << &Something1::s_value << " " << Something1::s_value << endl;
    
    
    
    

    return 0;
}
