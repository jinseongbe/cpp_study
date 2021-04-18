#include <iostream>

using namespace std;

template<class T, int size>
class StaticArray
{
private:
    T m_array[size];
    
public:
    T *getArray() { return m_array; }
    
    T &operator[](int index)
    {
        return m_array[index];
    }
    
    // 2. 사용하고자 하는 template 함수가 class 내부에 있을때(memberFunction)
    void print()
    {
        for (int count = 0; count < size; ++count)
        {
            std::cout << (*this)[count] << ' ';
        }
        std::cout << endl;
    }

};

// 1. 사용하고자 하는 template 함수가 class 외부에 있을때
//template <typename T, int size>
//void print(StaticArray<T, size> &array)
//{
//    for (int count = 0; count < size; ++count)
//    {
//        std::cout << array[count] << ' ';
//    }
//    std::cout << endl;
//}

// charType의 경우는 띄어쓰는것이 이상하므로 부분적으로 스페셜라이즈 해줌! 위에 함수와 비교해보시오
//template <int size>
//void print(StaticArray<char, size> &array)
//{
//    for (int count = 0; count < size; ++count)
//    {
//        std::cout << array[count];
//    }
//    std::cout << endl;
//}

// 2. 사용하고자 하는 template 함수가 class 내부에 있을때(memberFunction)
template <class T, int size>
class StaticArray2 : public StaticArray<T, size>
{
};

// 상속을 해준뒤 오버라이딩을 함으로써 부분적으로 템플릿을 스페셜라이즈 했음!
template <int size>
class StaticArray2<char, size> : public StaticArray<char, size>
{
public:
    void print()
    {
        for (int count = 0; count < size; ++count)
        {
            std::cout << (*this)[count];
        }
        std::cout << endl;
    }
};


int main()
{
    StaticArray<int, 4> int4;
    int4[0] = 1;
    int4[1] = 2;
    int4[2] = 3;
    int4[3] = 4;

//    print(int4);
    
//    2. 맴버로 집어넣은 경우
    int4.print();

    
    cout << endl;
    
    StaticArray<char, 14> char14;
    char14[0] = 'H';
    char14[1] = 'e';
    //...
    strcpy(char14.getArray(), "Hello, World");
//    print(char14);
    
//   2. 맴버로 집어넣은 경우
        char14.print();

    
    cout << endl;
    
    StaticArray2<char, 14> char14_2;
    strcpy(char14_2.getArray(), "Hello, World");
    char14_2.print();

    
    return 0;
}
