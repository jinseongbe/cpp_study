#include <iostream>

using namespace std;

int main()
{
    int length = 10;
    int length2 = 10;
    int length3 = 10;
    int length4 = 10;
    cin >> length4;
    
    int *array1 = new int[length];
    int *array2 = new int[length2]();       // 값을 넣어주지 않은 원소는 모두 0으로 초기화 한다!
    int *array3 = new int[length3]{};       // 이것도 위와 같이 0으로 채워짐
    int *array4 = new int[length4]{ 1, 2, 3, 4, 5, 6, 7, 9, 10 }; // 원소를 채우고 남은것은 0으로 채움
                                                                  // 만약 부족하게 할당하면 오류가남!
    
    array1[0] = 1;
    array1[1] = 4;
    array1[2] = 9;
    
    for (int i = 0; i < length; ++i)
    {
        cout << array1[i] << "\t";
//        cout << (uintptr_t)&array1[i] << endl;
    }
    cout << endl << endl;
    
    for (int i = 0; i < length2; ++i)
    {
        cout << array2[i] << "\t";
//        cout << (uintptr_t)&array2[i] << endl;
    }
    cout << endl << endl;
    
    for (int i = 0; i < length3; ++i)
    {
        cout << array3[i] << "\t";
//        cout << (uintptr_t)&array3[i] << endl;
    }
    cout << endl << endl;
    
    for (int i = 0; i < length4; ++i)
    {
        cout << array4[i] << "\t";
//        cout << (uintptr_t)&array4[i] << endl;
    }

    delete [] array1;
    delete [] array2;
    delete [] array3;
    delete [] array4;
    
    
    int fixedArray[] = { 1, 2, 3, 4, 5 };
    int *array = new int[]{ 1, 2, 3, 4, 5}; // 강사님은 사이즈 안정해주면 컴파일 안된다고 했는데 나는 됨?!
    delete[] array;
    
    // resizeing : 직접적으로는 안되고, 간접적으로 큰 메모리를 할당해서 있던 내용을 복사 할 수 있음

    return 0;
}
