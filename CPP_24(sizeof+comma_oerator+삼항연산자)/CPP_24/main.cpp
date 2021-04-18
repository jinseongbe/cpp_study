#include <iostream>

int main()
{
    using namespace std;
    
    // sizeof
    double a(0);
    
    cout << sizeof(float) << endl; // sizeof는 함수처럼 보이지만 연산자이다! 오퍼레이터!
    cout << sizeof(a) << endl;
    cout << sizeof a << endl << endl; // 변수는 괄호가 없어도 작동함!
    
    
    // comma operator, 풀어쓰는게 더 나을 수 도 있음
    int x = 3;
    int y = 10;
    int z = (++x, ++y); // ++x; ++y; int z = y;를 순서대로 작동함
    cout << x << " " << y << " " << z << endl;
    
    int x1 = 1, y1 = 10; // 여기서 사용되는 comma는 연산자가 아닌 구분 기호로 사용된것임
    int z1, z2;
    z1 = x1, y1; // comma 연산자의 우선순위가 대입연산자보다 낮아 그냥 z1에 x1이 대입된것임
    z2 = (++x1, x1 + y1);

    cout << z1 << endl;
    cout << z2 << endl << endl;
    
    //conditional operator(arithmetric if)(조건부연산자==삼항연산자)
    bool onSafe = true;
    int price;
    
    if (onSafe)
        price = 10;
    else
        price = 100;
    
    cout << price << endl;
    
    const int Price = (onSafe == true)? 10 : 100; // const 변수로 쓰려면 삼항연사자를 써야함
    cout << price << endl;
    //아니면 함수를 만들어서 사용 할 수 도 있지만 삼항연산자를 쓰는게 메모리를 덜 먹음, 그러나 복잡할 경우는 if문으로 쪼개서
    //사용하는 것이 더 나을 수 있다.
    
    
    //주의해야할점
    int x0 = 4;
    
    cout << ((x0 % 2 == 0 )? "even" : "odd") << endl;
    cout << ((x0 % 2 == 0 )? 0 : "odd") << endl; // 이렇게는 사용 할 수 없음!
    
    return 0;
}
