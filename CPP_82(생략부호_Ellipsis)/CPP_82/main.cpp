// 함수에 넣어주는값의 개수를 딱 정해놓고 싶지 않을때 사용
// 런타임 에러나 디버그 오류도 많아서 쉽게 사용하기는 어렵지만, 꼭 필요할때 쓰임

#include <iostream>
#include <cstdarg> // for ellipsis

using namespace std;

double findAverager(int count, ...)
{
    double sum = 0;
    
    va_list list;
    
    va_start(list, count);
    
    for (int arg = 0; arg < count; ++ arg)
        sum += va_arg(list, int);       // type을 미리 정해서 넣어줘야함!
    
    va_end(list);
    
    return sum / count;
}


int main(int argc, const char * argv[])
{
    cout << findAverager(1, 1, 2, 3, "Hello", 'c') << endl; // 1개를 제외한 나머지는 무시해버림!
    cout << findAverager(3, 1, 2, 3) << endl;               // 평균을 잘 냄
    cout << findAverager(5, 1, 2, 3, 4, 5) << endl;         // 평균을 잘 냄
    cout << findAverager(10, 1, 2, 3, 4, 5) << endl;        // 개수를 적게 넣어주면 오류 발생함!
    
    return 0;
}
