// 만약 친구의 정보를 저장해서 한번에 출력하고 싶은 프로그램을 만들고 싶다고 생각했을때
// Object(객체): 데이터와 기능이 묶여있는 것
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1
void print(const string &name, const string &address, const int &age,
           const double &height, const double &weight)
{
    cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
}


// 3
struct Friend
{
  string name;
  string address;
  int age;
  double height;
  double weight;
};

// 4
void print(const Friend &fr)    //함수 이름 같은건 오버로딩임!
{
    cout << fr.name << " " << fr.address << " " << fr.age << " "
    << fr.height << " " << fr.weight << endl;
}

// 5
class Friend_2
{
public:     //acess specifier (public, private, protected)
    string m_name;  // 맴버임을 알려주기 위해 m_을 붙이기도 하는데 최근에는 _name, name_ 이런식으로 쓰기도 함
    string address;
    int age;
    double height;
    double weight;
    
    void print()    //함수 이름 같은건 오버로딩임!
    {
        cout << m_name << " " << address << " " << age << " "
        << height << " " << weight << endl;
    }

};

int main()
{
    // 1.직접 한명씩 저장하여 출력
    string name;
    string address;
    int age;
    double height;
    double weight;
    
    print(name, address, age, height, weight);
    
    
    // 2.여러명일 경우 vector을 사용 할 수 있음
    vector<string> name_vec;
    vector<string> addr_vec;
    vector<int> age_vec;
    vector<double> height_vec;
    vector<double> weight_vec;
    
    print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weight_vec[0]);
    
    
    // 3.struct를 사용하는 경우
    Friend jj{"jackjack", "342-354", 2, 180, 70};
    //jj.name = "jackjack"  // 이렇게 하나씩 멤버를 지정해 줄 수 도 있음
    //jj.age =2;
    
    print(jj.name, jj.address, jj.age, jj.height, jj.weight);
    
    
    // 4.struct를 매개변수로 받는 print를 새로 정의
    print(jj);
    
    
    // 5.class 안에 출력 함수도 같이 넣어버림(기능과 데이터가 같이 있는 것을 오브젝트라 부름)
    Friend_2 jj_2{"jackjack", "342-354", 2, 180, 70}; //*
    jj_2.print();
    
    // instanciation : *실제로 메모리를 차지하지 않는것에 변수등을 넣어 메모리를 찾아주도록 정의해주는 것
    // instance      : 실제로 메모리를 차지하게된 대상변수(jj_2)
    
    
    // 6.그 밖에 예시(쓸모있는 예시가 아님)
    vector<Friend_2> my_friends;
    my_friends.resize(2);
    my_friends[0].print();
    my_friends[1].print();
    my_friends[2].print();
    // 이런반복을 다응과 같이 줄 일 수도 있음
    for (auto &ele : my_friends)
        ele.print();
    
    // 7.기타
    // struct에는 fuction을 안넣는게 일반적임! class를 사용할것!
    // struct에는 acess specifier가 존재하지 않음!
 
    return 0;
}
