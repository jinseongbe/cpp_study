#include "Student.h"
#include "Teacher.h"

using namespace std;

int main()
{
    Student std("JackJack");
    Teacher teacher("Dr.Hong");
    
    std.setName("Jack2");
    
    cout << std.getName() << " " << std.getIntel() << endl;
    
    teacher.setName("Dr,K");
    cout << teacher.getName() << endl;
    
    
    cout << std << endl;
    cout << teacher << endl;
    
    std.doNothing();
    teacher.doNothing();
    
    std.study();
    teacher.teach();
    
    Person person;
    person.setName("Mr,P");
    cout << person.getName() << endl;
    
    return 0;
}
