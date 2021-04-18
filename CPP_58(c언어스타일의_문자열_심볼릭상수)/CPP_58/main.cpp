#include <iostream>

using namespace std;

const char *getName()
{
    return "JackJack";
}


int main()
{
    char name[] = "Jack Jack";
//    char *name = "Jack Jack";                 // 주소이기 때문에 바로 사용 할 수 없음!!
    const char *name1 = "Jack Jack";
    const char *name2 = "Jack Jack";            // 컴파일러가 같은 상수는 하나의 메모리로 사용하게 바꿔줌(주소같다)
    const char *name3 = "Jack Jack!";
    const char *name4 = getName();
    
    cout << (uintptr_t)name1 << endl;
    cout << (uintptr_t)name2 << endl;
    cout << (uintptr_t)name3 << endl;
    cout << (uintptr_t)name4 << endl;

    
    // 포인터 문자열에서 특이한 것
    int int_arr[5] = { 1, 2, 3, 4, 6};
    char char_arr[] = "Jack_come";
    const char *name_ptr = "Jack_Come";
    
    cout << int_arr << endl;
    cout << char_arr << endl; // 문자의 경우 주소가 출력되는 것이 아니라 cout 내부에서 주소가 아닌
    cout << name_ptr << endl; // 문자로 가정하여 문자열을 그대로 출력한다! 예외상황이니 알아 둘 것!
    
    char c = 'Q';
    cout << &c << endl;       // c가 문자열이라고 가정하고 쭉 출력해서 뒤에 뭐가 나올지 모름!
    cout << *&c << endl;
    
    return 0;
}
