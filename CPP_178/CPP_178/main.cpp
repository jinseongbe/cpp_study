#include <iostream>
#include <vector>
#include <algorithm>    // std::min

// Reference : http://thbecker.net/articles/auto_and_decltype/section_01.html

using namespace std;

class Examples
{
public:
    
    void ex1()
    {
        std::vector<int> vect;
        // auto가 생기기 전
        for (std::vector<int>::iterator itr = vect.begin(); itr !=vect.end(); ++itr)
            cout << *itr;
        
        // auto 생긴 후
        for (auto itr = vect.begin(); itr != vect.end(); itr++)
            cout << *itr;
        
        // 최근에 사용 가능한 더 줄인 문법
        for (auto itr : vect)   // for (const auto & itr : vect)
            cout << itr;
    }
    
    
    void ex2()
    {   // auto는 가장 기본적인 자료형만 자동으로 추론해주고, 나머지 자잘한 것들은 사용자가 의도하는대로 추가하는 구조이다.
        int x = int(10);
        
        auto auto_x = x;
        
        const int &crx = x;
        
        auto auto_crx1 = crx;       // 위에서 const int로 넣어줬지만 auto_crx1은 int로 인식됨,이유는 auto는 const,ref를 다 떼어버림!! 중요한 성질!
        const auto & auto_crx2 = crx;   // const로 쓰고 싶다면 다음과 같이 사용 하면, const int reference로 작동함
        
        volatile int vx = 1024;     // volatile : 값이 자주 바뀌기 때문에 최적하 할때 빼달라(배제해달라) - 멀티쓰레딩을 사용 할 때 사용가능
        auto avx = vx;              // volatile역시 auto를 거치면 떼어지기 때문에, volatile로 사용하고 싶다면 아래와 같이 사용해야한다.
        volatile auto vavx = vx;
    }

    

    template<class T1>
    void func_ex3_1(T1 arg)
    {}
    
    template<class T2>
    void func_ex3_2(const T2& arg)
    {}
    
    void ex3()
    {
        const int &crx = 123;
        
        func_ex3_1(crx);    // 이 경우는 ex3<int arg>로 들어가게 된다
        func_ex3_2(crx);    // 아 경우는 ex3<const int &arg>
    }
    
    
    void ex4()
    {
        const int c = 0;
        auto &rc = c;   // 여가서 auto를 썻기 떄문에 const가 없어졌다고 볼 수 있다.
                        // 그러나 reference auto로 받기 때문에 auto가 자동으로 const int로 인식한다
        // rc = 123;    // 따라서 값을 바꾸려고 하면 error 발생
    }
    
    void ex5()
    {
        int i = 42;
        auto && ri_1 = i;   // l-value
        auto && ri_2 = 42;  // r-value
        // 오른쪽에서 대입되는 값이 l-value이면 l값으로 r-value 이면 r값으로 자동으로 넣어줌
    }
    
    void ex6()
    {
        int x = 42;
        const int *p1 = &x;
        auto p2 = p1;       // const int pointer로 자동으로 인식해줌
        // *p2 = 45;        // 따라서 바꾸려고 들면 error발생함!
    }
    
    
    // auto가 반드시 필요한 경우!
    template<typename T, typename S>
    void func_ex7(T lhs, S rhs) // 곱하기를 하는데 들어오는 데이터 타입이 다를 경우~, 어떤 데이터 타입이 출력되는지 알고자함
    {
        // 1. auto사용
        auto prod1 = lhs * rhs; // 이런 방식으로 사용하면 해결 가능
        
        
        // 2. 예전의 방식, 데이터 타입을 리턴해주는 함수를 사용했음
//        typedef typeof(lhs * rhs) product_type;     // pre-c++11 'some' compilers
        typedef decltype(lhs * rhs) product_type;     // 이름이 바뀜, 이때 lhs * rhs부분은 실제로 계산하는 것이 아니라추론만 하는 기능을 함
        product_type prod2 = lhs * rhs;
        
        // 3. 이렇게 바로 사용 할 수 도 있음
        decltype(lhs * rhs) prod3 = lhs * rhs;
    }
    
    
    

    template<typename T, typename S>
    // decltype(lhs * rhs) func_ex8(T lhs, S rhs)   // 아렇게는 사용 불가, 컴파일러가 읽는 순서를 생각했을때, lhs rhs가 무엇인지 모르기 떄문
    auto func_ex8(T lhs, S rhs) -> decltype(lhs * rhs)
    {   // 이렇게 바로 return 하도록 사용 가능하다!
        return lhs * rhs;
    }
    
    void ex7_8()
    {
        func_ex7(1.0, 254);
        func_ex8(1.2, 235);
    }
    
    
    
    struct S
    {
        int m_x;
        
        S()
        {
            m_x = 42;
        }
    };
    
    void ex9()
    {
        int x;
        const int cx = 42l;
        const int &crx = x;
        const S *p = new S();
        
        // 위에서의 예제에서 본것들 처럼, auto는 const와 ref를 뗴어버린다
        auto a = x;
        auto b = cx;
        auto c = crx;
        auto d = p;
        auto e = p->m_x;
        
        // typedef decltype은 auto와 다르게 원래 변수 형태를 그대로 가져온다, const ref 등등
        typedef decltype(x)         x_type;
        typedef decltype(cx)        cx_type;
        typedef decltype(crx)       crx_type;
        typedef decltype(p->m_x)    m_x_type;   // 'declared' type
        
        // ()안에 넣어주면, reference로 바뀜
        typedef decltype((x))       x_with_parens_type;     // add references to lvalues
        typedef decltype((cx))      cx_with_parens_type;
        typedef decltype((crx))     crx_with_parens_type;
        typedef decltype((p->m_x))  m_with_parens_type;
        
    }
    
    
};


int main()
{
    Examples ex;
    
    ex.ex1();
    ex.ex2();
    ex.ex3();
    
    
    return 0;
}
