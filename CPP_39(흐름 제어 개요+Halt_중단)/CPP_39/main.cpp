#include <iostream>
#include <cstdlib> // exit를 사용하기 위해서 include

using namespace std;

int main()
{
    //Halt(중단)
    
    cout << "I love u" << endl;
    
    return 0;   // 이렇게해서 중단 할 수 있으나, 아래에 버려지는 코드를 주석처리하든지 설명을 해주는 것이 좋음
    exit(0);    // #include <cstdlib> 필요, return 보다 더 강력하게,긴급하게 종료해야한다는 늬앙스가 큼
                // 디버깅 할때 종종 사용함
    
    cout << "me 2" << endl;

    return 0;
}

/*
- Control flow(흐름제어)

 Halt(중단)
 : return, exit
 
 Loops(반복)
 : while, do while, for,
 
 Jump(점프)
 : goto(잘안씀), break, continue
 
 Exceptions(예외 처리)
 : try, catch, throw
 
 Conditional branches(조건 분기)
 : if, switch
 */
