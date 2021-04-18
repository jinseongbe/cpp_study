#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void printlength(array<int, 5> my_arr);

int main()
{
//    int array[5] = { 1, 2, 3, 4, 5}; //기존의 방식
    
    std::array<int, 5> my_arr = { 1, 2, 3, 4, 5}; // 여기서는 원소의 크기(5)가 생력되면 안된다!
    for(int i = 0; i < 5; ++i)
        cout << my_arr[i] << "\t";

    my_arr = { 1, 3, 4 }; // 적게 넣으면 나머지는 0으로 많이 넣으면 오류발생 - 기존 방법과 동일
    for(int i = 0; i < 5; ++i)
        cout << my_arr[i] << "\t";
    cout << endl << endl;

    
    
    cout << my_arr[10] << endl;         // 무조건 실행, 10개가 없어도 실행됨
//    cout << my_arr.at(10) << endl;      // 예외처리로 메세지 발생, 위의 방법보다는 약간 느리긴함

    cout << my_arr.size() << endl;
    printlength(my_arr);

    cout << endl << endl;

    
    
    array<int, 5> my_arr2 = { 5, 46, 78, 32, 9 };

    for (auto &element : my_arr2)       //for each도 사용 가능!
        cout << element << "\t";
    cout << endl;
    
    std::sort(my_arr2.begin(), my_arr2.end());      //범위를 지정할 수 도 있음, 중간부터 도는 중간까지 등등
    for (auto &element : my_arr2)
        cout << element << "\t";
    cout << endl;
    
    std::sort(my_arr2.rbegin(), my_arr2.rend()); // reverse sort!
    for (auto &element : my_arr2)       //for each도 사용 가능!
        cout << element << "\t";

    cout << endl << endl;
    
    
    return 0;
}

void printlength(array<int, 5> my_arr)      // 이렇게 사용하면 복사해서 사용하는것임 -> 포인터 또는 레퍼런스로!
{                                                  // const로 값이 변하지 않게 사용 할 수도 있다.
    cout << my_arr.size() << endl;
}
