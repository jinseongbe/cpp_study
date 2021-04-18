#include <iostream>

using namespace std;

int main()
{
    int value = 7;                      // int는 4칸씩 이동
    int *ptr1 = &value;
    cout << uintptr_t(ptr1) << endl;
    cout << uintptr_t(ptr1 + 1) << endl;
    cout << uintptr_t(ptr1 - 1) << endl;
    cout << uintptr_t(ptr1 + 2) << endl << endl;

    double value2 = 7.0;                // double은 8칸씩 이동
    double *ptr2 = &value2;
    cout << uintptr_t(ptr2) << endl;
    cout << uintptr_t(ptr2 + 1) << endl;
    cout << uintptr_t(ptr2 - 1) << endl;
    cout << uintptr_t(ptr2 + 2) << endl << endl;

    
    int array[] = { 9, 7, 5, 3, 1};
    int *ptrArray = array;
    
    for(int i = 0; i < 5; ++i)
    {
        cout << array[i] << " " << (uintptr_t)&array[i] << endl;
    }
    cout << endl;
    
    for(int i = 0; i < 5; ++i)
    {
        cout << *(ptrArray + i) << " " << (uintptr_t)(ptrArray + i) << endl;
    }
    cout << endl << endl;


    char name[] = "sung sung";
    const int n_name = sizeof(name) / sizeof(name[0]);
    char *ptrName = name;
    cout << n_name << endl;
    
    for(int i = 0; i < n_name; ++i)
    {
        cout << *(ptrName + i);
    }
    
    return 0;
}
