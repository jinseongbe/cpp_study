#include <iostream>
#include <vector>
//#include <array>

using namespace std;

int main()
{
    
//    std::array<int, 5> my_arr     // std::array의 경우 크기를 정해줬어야함!
//    std::vector<int> array;         // std::vector의 경우는 동적할당이라서 딱히 정해줘도 그만 안정해줘도 문제x
                                      // 그때 그때 사이즈를 바꿀 수 도 있음!
    std::vector<int> array1 = { 1, 2, 3, 4, 5};
    cout << array1.size() << endl;
    
    std::vector<int> array2 = { 1, 2, 4, };
    cout << array2.size() << endl;
    
    std::vector<int> array3 { 1, 3, 5, 6};          //uniform initialization
    cout << array3.size() << endl;
    
    cout << endl << endl;
    
    
    
    vector<int> arr1 = { 1, 2, 3, 4, 5, 6};
    for(auto &itr : arr1)
        cout << itr << "\t";
    cout << endl;
    
    cout << arr1[1] << endl;
    cout << arr1.at(1) << endl;              // 이 경우 사이즈를 벗어난 원소를 고를 경우 예외처리함!
    cout << arr1.size() << endl;             // 사이즈도 쉽게 알 수 있음!
    
    arr1.resize(10);
    cout << arr1.size() << endl;             // 리사이즈도 쉽게 가능!
    for(auto &itr : arr1)
        cout << itr << "\t";

    arr1.resize(2);
    cout << arr1.size() << endl;             // 줄이는 것도 가능하다!
    for(auto &itr : arr1)
        cout << itr << "\t";
    cout << endl;

    // vector의 장점은 알아서 메모리를 지워준다!
    // 블럭 밖으로 나가거나, return 밖을 나가면 메모리에서 사라진다!!
    // 또한 자신의 길이를 알아서 기억하기 때문에 함수의 파라미터로 보내도 알아서 기억하고 있다
    //
    
    return 0;
}
