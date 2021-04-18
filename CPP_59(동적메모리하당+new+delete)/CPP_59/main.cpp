#include <iostream>

using namespace std;

int main()
{
    // 메모리 할당 3가지
    // 1.정적메모리 할당 : 전역변수나 스테틱변수와 같이 한번 할당 되면 프로그램이 종료 될때까지 메모리를 가지고 있음
    // 2.자동메모리 할당 : 변수를 선언하거나, 정적배열을 선언했을때 블럭을 벗어나면 메모리를 다시 os로 반납함
    // 3.동적메모리 할당 :
    
    int array[1000000];             // stack : 정적메모리가 저장되는 공간인데 매우 용량이 작다!
    
    int *ptr1 = new int;            // os에서 4byte(int)의 메모리 공간의 주소를 받아옴
    *ptr1 = 7;                      // 이것은 정적메모리에서 int var = 7; 과 같은 결과지만 다르다는것!
    
    cout << ptr1 << endl;
    cout << *ptr1 << endl << endl;
    
    delete ptr1;
    ptr1 = nullptr;

    cout << "After delete" << endl;
//    cout << ptr1 << endl;
//    cout << *ptr1 << endl << endl;

    
    int *ptr2 = new int{ 8 };       // 이렇게도 초기화 가능!
    cout << ptr2 << endl;
    cout << *ptr2 << endl << endl;

    delete ptr2;                    // 명시를 안해주면 프로그램이 끝나고 알아서 메모리를 회수해감
    
    
    int *ptr3 = new(std::nothrow) int{ 7 }; // 메모리가 부족할때 오류처리하지 않고 null ptr을 대입함
    
    
    // 흔히 할 수 있는 실수
    
    int *ptr4 = new(std::nothrow) int{ 7 };
    int *ptr5 = ptr4;
    
    delete ptr4;
    ptr4 = nullptr;
    
    
    // 메모리 누수!! 무시무시한 문제(memory leak)
    
    while(1)
    {
        int *ptr6 = new int;
        cout << ptr6 << endl;
        
        delete ptr6; // delete로 지워주지 않으면 메모리가 무한하게 사용됨! 계속 메모리를 할당받음!! 심각한문제임!
    }                // 추가적으로 new와 delete는 처리가 좀 느리기 때문에 프로그램 성능을 높히려면 적게 사용해야함
    
    return 0;
}
