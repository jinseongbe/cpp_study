#include <iostream>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
    unsigned m_length = 0;
    int *m_data = nullptr;
    
public:
    IntArray(unsigned length)
    : m_length(length)
    {
        m_data = new int[length];       // 중복되는 기능은 쪼개서 한곳에서만 작동되게 하는것이 좋음
    }

    IntArray(const std::initializer_list<int> &list)
    : IntArray(list.size())
    {
        int count = 0;
        for (auto &e : list)
        {
            m_data[count] = e;
            ++count;
        }
//        for (unsigned count = 0; count < list.size(); ++count)
//            m_data[count] = list[count]; // error : initializer operator는 []을 제공하지 않음!!
    }
    
    ~IntArray()
    {
        delete[] this->m_data;
    }
    
    friend ostream &operator << (ostream &out, IntArray &arr)
    {
        for(unsigned i = 0; i < arr.m_length; ++i)
        {
            out << arr.m_data[i] << " ";
        }
        out << endl;
        return out;
    }
};

int main()
{
    int my_arr1[5] = { 1, 2, 3, 4, 5};
    int *my_arr2 = new int[5]{ 1, 2, 3, 4, 5};
    
    auto il = { 10, 20, 30 };       // #include <initializer_list>애서 자동으로 list로 만들어 주는것임!
    
    IntArray int_array { 1, 2, 3, 4, 5 };
    IntArray int_array2 = { 1, 2, 3, 4, 5 };
    IntArray int_array3 { 1, 2, 3, 4, 5, 8, 7, 5, 7 };
    
    cout << int_array << endl;
    cout << int_array2 << endl;
    cout << int_array3 << endl;
    
    return 0;
}
