#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

int main()
{
    using namespace std;
    
    Student *std1 = new Student("JackJack", 0);
    Student *std2 = new Student("Dash", 1);
    Student *std3 = new Student("Violet", 2);
    // Student std3("Violet", 2); 이렇게도 선언해서 사용 할 수 있지만 이 경우에는
    //                            main함수가 끝나게 되면 함수가 종료되면서 변수도 다 없어진다
    //                            따라서 다른 함수에서 사용하고 싶거나 해서 사라지지 않게 하려면 위와같이
    //                            동정할당을 사용하여 정의해주면 된다! 그리고 이 경우는 마지막에 꼭 delete해줄것!!!
    // 분산처리 할 때는 이런식으로 코딩 할 수 없다!!
    // 분산처리(컴퓨터가 메모리와 분리되어 있음)

    Teacher *teacher1 = new Teacher("Prof.Hong");
    Teacher *teacher2 = new Teacher("Prof.Good");
    
    // Composition Relationship
/*  Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(Teacher("prof.Hong"));
    lec1.registerStudent(Student("JackJack", 0));
    lec1.registerStudent(Student("Dash", 1));
    lec1.registerStudent(Student("Violet", 2));
    
    Lecture lec2("Computational Thingking");
    lec2.assignTeacher(Teacher("Prof.Good"));
    lec2.registerStudent(Student("JackJack", 0));
*/
    
    // TODO: implement Aggregation Relationship
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(teacher1);
    lec1.registerStudent(std1);
    lec1.registerStudent(std2);
    lec1.registerStudent(std3);
    
    Lecture lec2("Computational Thingking");
    lec2.assignTeacher(teacher2);
    lec2.registerStudent(std1);

    // test
    {
        cout << lec1 << endl;
        cout << lec2 << endl;
        
        // event
        lec2.study();
        
        cout << lec1 << endl;
        cout << lec2 << endl;
    }

    // TODO: delete memory (if necessary)
    delete std1;
    delete std2;
    delete std3;
    
    delete teacher1;
    delete teacher2;
    
    return 0;
}
