#include <iostream>

using namespace std;

struct Person
{
    int age;
    double weight;
};

int main()
{
    Person person1;
    person1.age = 5;        // 여기서 struct안에 들어있는 age와 weight가 멤버임
    person1.weight = 30.5;
    
    Person &ref_per1 = person1;
    ref_per1.age = 15;
    ref_per1.weight = 32.7;
    
    Person *ptr_per1 = &person1;
    ptr_per1->age = 17;
    (*ptr_per1).age = 16; // 이렇게 까지 쓰진 않음,, 그냥 할 수 도 있다!
    
    Person &ref_per2 = *ptr_per1;
    ref_per2.age = 90;
    
    cout << &person1 << endl;
    cout << &ref_per2 << endl;
    
    
    return 0;
}
