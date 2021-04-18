#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

enum StudenName // 권장하진 않으나 할 수 있음!
{
    JACKJACK,   // = 0
    DASH,       // = 1
    VIOLET,     // = 2
    NUM_STUDENT // = 3
};


int main()
{
    int student_score;      // 1 int
    int student_scores[5];  // 5 int, 빅데이터와 같이 많은 데이터를 다룰때 특정경우 메모리를 초과하여 받아올수 없을수도 있다.
    
    cout << sizeof(student_score) << endl;
    cout << sizeof(student_scores) << endl << endl;
    
    student_scores[0] = 100;    // 1st element
    student_scores[1] = 80;     // 2nd element
    student_scores[2] = 90;     // 3rd element
    student_scores[3] = 50;     // 4th element
    student_scores[4] = 0;      // 5th element
    
    for(int i = 0; i < 5; i++)
    {
        cout << student_scores[i] << endl;
    }
    cout << endl;
    
    cout << (student_scores[3] + student_scores[2]) / 2.0 << endl;
    
    
    // 구조체에서도 배열 사용 가능!
    cout << sizeof(Rectangle) << endl;
    Rectangle rect_arr[10];
    cout << sizeof(rect_arr) << endl;
    
    rect_arr[0].length = 1;
    rect_arr[0].width = 2;
    cout << endl;
    
    
    // 배열 초기화 여러가지 방법들
    int my_array1[5] = { 1, 2, 5 }; // 부족한 개수는 0으로 뒤에 채워 넣음
    for(int i = 0; i < 5; i++)
    {
        cout << my_array1[i] << endl;
    }
    cout << endl;
    
    int my_array2[] = { 1, 2, 3, 4, 5, 7, 8 };
    for(int i = 0; i < 7; i++)
    {
        cout << my_array2[i] << endl;
    }
    cout << endl;
    
    int my_array3[]{ 1, 2, 4, 5 };
    for(int i = 0; i < 4; i++)
    {
        cout << my_array3[i] << endl;
    }
    cout << endl;
    
    
    // enum도 활용 가능함
    int student_arr[NUM_STUDENT];
    student_arr[0] = 56;
    student_arr[DASH] = 43;
    student_arr[2] = 23;
    cout << student_arr[JACKJACK] << endl;
    cout << student_arr[DASH] << endl;
    cout << student_arr[VIOLET] << endl;
    cout << endl;
    
    
    // array를 정의 할 때 사이즈가 컴파일 타임에 고정되어야만 한다!?고 강의해서 했는데 실제론 사용 가능,,?
    int arr_size;
    cin >> arr_size;
    
    int array_1[arr_size]; // 런타임에 배열의 크기가 결정된다!
    
    for (int i = 0; i < arr_size; i++)
    {
        cin >> array_1[i];
    }
    for (int i = 0; i < arr_size; i++)
    {
        cout << array_1[i] << endl;
    }

    return 0;
}
