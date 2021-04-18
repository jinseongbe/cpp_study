#include <iostream>
#include <cassert>

using namespace std;

class IntList1
{
private:
    int m_list[10];
    
public:
    void setItem(int index, int value)
    {
        m_list[index] = value;
    }
    
    int getItem(int index)
    {
        return m_list[index];
    }
    
    int *getList()
    {
        return m_list;
    }
};

class IntList2
{
private:
    int m_list[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
public:
    int &operator [] (const int index)      // 용도에 따라 여러 자료형파라미터사용가능(string, double, int etc..)
    {                                       // referance로 return한 이유는 값을 자유롭게 바꾸고 부를수 있도록 하기 위함임!
        assert(index >= 0);
        assert(index < 10);                 // 또한 assert를 사용혀여 큰값이나 작은 값이 들어왔을때 알려줄수있도록!!
                                            // if문은 너무 느리기 때문에 깔끔한 assert 사용할것!
        return m_list[index];
    }
    
    const int &operator [] (const int index) const
    {
        assert(index >= 0);
        assert(index < 10);

        return m_list[index];
    }
};

int main()
{
    IntList1 my_list1;
    my_list1.setItem(3, 1);
    cout << my_list1.getItem(3) << endl;
    
    my_list1.getList()[3] = 10;
    cout << my_list1.getList()[3] << endl;
    cout << endl;
    
    
    IntList2 my_list2;
    my_list2[3] = 20;
    cout << my_list2[3] << endl;
    
    const IntList2 my_list3;
//    my_list3[3] = 20;             // const로 정의한경우,operator 함수를 const로 바꿔주고, 초기화 해줘야함
    cout << my_list3[3] << endl;    // 그리고 그 결과 값을 읽을 순 있지만 바꿀수는 없음! (추가적으러, const오버로당으로 구현가능한것에 주목!)
    
    
    // 사소한 주의사항!!
    IntList2 *list = new IntList2;
//    cout << list[3]  << endl;    // lint[3] = 10; - not OK
    cout << (*list)[3] << endl;    // OK, 디레퍼런싱한다음에 사용해야함! 주의할것
    
    
    
    return 0;
}
