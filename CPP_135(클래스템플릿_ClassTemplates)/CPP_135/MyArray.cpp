#include "MyArray.h"

// 이렇게만 할경우 링킹에러 발생함
//template<typename T>
//void MyArray<T>::print()
//{
//    for (int i = 0; i < m_length; ++i)
//        std::cout << m_data[i] << " ";
//    std::cout << std::endl;
//}

// 다른 좋은 해결법!
template<typename T>

void MyArray<T>::print()
{
    for (int i = 0; i < m_length; ++i)
        std::cout << m_data[i] << " ";
    std::cout << std::endl;
}
// explicit instantiation

// 1. 각각을 explicit instantiation 해주는 방법
//template void MyArray<double>::print();
//template void MyArray<int>::print();
//template void MyArray<char>::print();

// 2. 한번에 해주는 방법
template class MyArray<double>;
template class MyArray<int>;
template class MyArray<char>;
