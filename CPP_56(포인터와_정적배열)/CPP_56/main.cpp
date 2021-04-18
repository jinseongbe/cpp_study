#include <iostream>

using namespace std;

void printArray(int array[]);

int main()
{
    //array는 pointer이다!! 즉 배열은 주소이다!
    int array[5] = { 9, 7, 8, 3, 1};
    
    cout << array[0] << " " << array[1] << endl;
    cout << array << endl;
    cout << &array[0] << endl;
    cout << *array << endl;
    

    char name[] = "jackjack";
    cout << *name << endl;
    
    
    int *ptr = array;
    cout << ptr << endl;
    cout << *ptr << endl;
    
    
    //pointer 와 array 차이점! : 기능을 편하게 하기 위한 것
    int array1[5] = { 1, 2, 4, 3, 5};
    int *ptr1 = array1;
    
    cout << sizeof(array1) << endl;         // 배열에 있는 원소들의 사이즈 20byte
    cout << sizeof(ptr1) << endl;           // 포인터 주소의 사이즈 8byte
    
    printArray(array1);                     // 같은 배열인데 함수로 sizeof를 실행하면 8byte가 나옴
    
    cout << array1[0] << " " << *array1 << endl; // 함수안에서 배열의 값을 바꿔준것이 저장되어 나옴!!
    
    
    cout << *ptr << " " << *(ptr + 1) << endl;   // 포인터 연산! 다음 주소에 있는것을 출력함!
    
    
    return 0;
}

void printArray(int array[]) // 내부적으로 보면 배열이지만 사실상 포인터로 들어간거다!
{
    cout << sizeof(array) << endl;
    cout << *array  << endl; // de-referensing
    
    *array = 100;
}
// void printArray(int *array) // 이것과 같은 함수임
