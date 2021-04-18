#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int x, y;
    cin >> x >> y;
    
    int op;
    cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
    cin >> op;
    
    // static binding (early binding)
//    int result;
//    switch (op)
//    {
//        case 0: result = add(x, y); break;
//        case 1: result = subtract(x, y); break;
//        case 2: result = multiply(x, y); break;
//    }
//
//    cout << result << endl;
    

    // Dynamic binding (late binding)
    int(*func_ptr)(int, int) = nullptr;
    switch (op)
    {
        case 0: func_ptr = add; break;
        case 1: func_ptr = subtract; break;
        case 2: func_ptr = multiply; break;
    }

    cout << func_ptr(x, y) << endl;
        
    // 속도는 static binding이 더 빠름! Dynamic binding은 아무래도 주소를 한번 거쳐야 하기 때문이다
    // 그렇지만 Dynamic binding은 유용성이 좋음! 여러 반복문에 사용한다든지 등등?
    // 하지만 너무 많이 반복되는 곳에 사용되는것은 좋지않음! 느리기 때문에!
    
    return 0;
}
