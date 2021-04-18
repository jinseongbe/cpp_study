#include <iostream>

using namespace std;

void doSomething(int students_scores[]) // 이것은 배열이 아니다!!! 중요! 문법상 배열이 아니라 포인터임!
{                                         // 컴파일러는 내부적으로 포인터로 처리한다!
    cout << (long long)&students_scores << endl; // 배열이 아니라 포인터 변수이다! 첫번째 주소를 저장하는 다른 변수의 주소임
    cout << (long long)&students_scores[0] << endl; // 이것은 원래 배열의 첫번째 원소의 주소를 나타냄!
    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << endl;
    cout << students_scores[3] << endl;
    cout << "size in doSomting : " << sizeof(students_scores) << endl;
    // 여기서 사이즈는 포인터의 사이즈이다! 32bits에서는 주소가 4byte이고 64bits에서는 주소가 8byte!
}

int main()
{
    const int num_students = 20;
//    int num_students;
//    cin >> num_students;
    
    int students_scores[num_students] = {1, 2, 3, 4, 5,}; // 배열로 선언됨: 이름 자체가 주소임
                                                          // 인덱스(num_studenta)로는 정수형이면 모두 가능!
    cout << (long long)students_scores << endl;     // 배열은 주소로써 동작하기 때문에 주소연산자가 없어도 주소를 출력함
    cout << (long long)&students_scores << endl;    // 배열의 주소는 내부적으로 첫번째 주소를 가지고 있음
    cout << endl;
    cout << (long long)&students_scores[0] << endl;
    cout << (long long)&students_scores[1] << endl;
    cout << (long long)&students_scores[2] << endl;
    cout << (long long)&students_scores[3] << endl;
    cout << "size in main : " <<sizeof(students_scores) << endl;
    
    
    cout << endl << "in doSomthing" << endl;
    doSomething(students_scores); // 배열을 가져올때 첫번쩨 주소 값을 복사에서 가져오는 것이지 배열의 원소를 모두 가져오는 것이 아니다!
    
    cout << endl;
    return 0;
}
