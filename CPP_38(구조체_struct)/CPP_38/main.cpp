#include <iostream>

using namespace std;

struct Person
{
    double  height;
    float   weight;
    int     age;
    string  name;
    
    void print()
    {
        cout << height << "\t" << weight << "\t" << age << "\t" << name;
        cout << endl;
    }
    
};

void printPerson(Person ps)
{
    cout << ps.height << "\t" << ps.weight << "\t" << ps.age << "\t" << ps.name;
    cout << endl;
}

struct Family
{
    Person me;
    Person mom;
    Person dad;
    //    Person me, mom, ded; // 이렇게도 가능!
};

struct Person2 // 내부에서 선언하면 기본값으로 들어감! 그렇지만 사용자가 다시 선언하는게 우선으로 저장됨
{
    double  height = 100.0;
    float   weight = 30.0;
    int     age = 15;
    string  name = "name";
};

struct Employee     // 2 + 4 + 8 = 14 bytes
{
    short   id;     // 2 bytes
    int     age;    // 4 bytes
    double  wage;   // 8 bytes
};




int main()
{
//    double  height;
//    float   weight;
//    int     age;
//    string  name;
    
    Person me;
    me.age = 20; // '.' member select operator
    me.name = "JackJcak";
    me.height = 2.0;
    me.weight = 100.0;

    Person mom{1.5, 60.0, 40, "alsiss"};
    Person dad;
    
    printPerson(me);
    me.print();
    
    printPerson(mom);
    
    
    // 대입 연산자로도 가능하지만, 내부 구조가 복잡해져서 의도한데로 동작 하지 않을 수 도 있다.
    Person me_copy1(me);
    me_copy1.print();
    
    Person me_copy2 = me;
    me_copy2.print();
    
    
    Person2 me2;
    
    
    Employee emp1;
    
    cout << sizeof(emp1) << endl; // 16 bytes로 출력됨, 컴퓨터가 저장하는데 2bytes를 저장하기 힘들어 4bytes로 저장함(padding: 2bytes짜리에 2bytes가 더해져 4bytes가 되는 현상!)
    
    return 0;
}
