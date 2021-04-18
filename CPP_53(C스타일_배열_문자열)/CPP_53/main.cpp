#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    
    char myString[] = "string"; // "string\0" : \0(null) 생략되어 있음 따라서 7글자임
    
    for (int i = 0; i < 7 ; ++i)
    {
        cout << myString[i] << " " << (int)myString[i] << endl;
    }
    cout << endl;
    
    cout << sizeof(myString) / sizeof(myString[0]) << endl;
    
    
    
    char string1[255];
    cin >> string1;
    cin.getline(string1, 255); // 빈칸도 입력 받을 수 있다
    
    string1[0] = 'A';
    string1[10] = '\0';
    cout << string1 << endl << endl;
    

    char string2[255];
    cin.getline(string2, 255); // 빈칸도 입력 받을 수 있다

    int ix = 0 ;
    while(1)
    {
        if(string2[ix] == '\0') break;
        
        cout << string2[ix] << " " << (long long)string2[ix] << endl;
        ++ix;
    }
    
    
    // 전통적인 c스타일 문자열 코딩
    char source[] = "Copy this!";
    char dest[50];                  // 여기서 source의 메모리 보다 적은(50 대신 작은 수)를 넣으면 문제생김!!런타임에러
    strcpy(dest, source);           // source에 있는것을 dest에 넣는 함수
    
    cout << source << endl;
    cout << dest << endl;
    cout << endl << endl;
    
    // strcat() 한 문자열 뒤에 붙이는 것
    char pp[] = "puls!!";
    strcat(dest, pp);
    cout << dest << endl;
    cout << endl << endl;
    
    // strcmp 두 문자열을 비교하여 같으면 0을 return!! if문 쓸때 주의!!! : if(strcmp(source, dest) == 0)
    char source2[] = "Copy this!";
    cout << strcmp(source, dest) << endl;
    cout << strcmp(source, source2) << endl;
    
    return 0;
}
