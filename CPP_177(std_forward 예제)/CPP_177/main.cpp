#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>  // std::forward

using namespace std;

class CustomVector
{
public:
    unsigned n_data = 0;
    int *ptr = nullptr;
    
    CustomVector(const unsigned & _n_data, const int & _init = 0)
    {
        cout << "Constructor" << endl;
        
        init(_n_data, _init);
    }
    
    CustomVector(CustomVector & l_input)
    {
        cout << "Copy constructor" << endl;
        
        init(l_input.n_data);
        
        for (unsigned i = 0; i < n_data; ++i)
        {
            ptr[i] = l_input.ptr[i];
        }
    }
    
    CustomVector(CustomVector && r_input)
    {
        cout << "Move constructor" << endl;
        
        n_data = r_input.n_data;
        ptr = r_input.ptr;
        
        r_input.n_data = 0;
        r_input.ptr = nullptr;
    }

    ~CustomVector()
    {
        delete[] ptr;
    }
    
    void init(const unsigned & _n_data, const int & _init = 0)
    {
        n_data = _n_data;
        ptr = new int[n_data];
        for (unsigned i = 0; i < n_data; ++i)
        {
            ptr[i] = _init;
        }
    }
};

void doSomething(CustomVector & vec)
{
    cout << "Pass by L-reference" << endl;
    CustomVector new_vec(vec);
}

void doSomething(CustomVector && vec)
{
    cout << "Pass by R-reference" << endl;
    CustomVector new_vec(std::move(vec));
//    CustomVector new_vec(vec);            // note : vec itself is L-value, 즉 위에서 &&vec(R-value)로 받아오더라도 이렇게 쓰면 L-value로 인식하고
                                            // copyconstructor를 호출하게 된다!
}


template<typename T>
void doSomethingTemplate1(T vec)
{
    doSomething(vec);
}

template<typename T>
void doSomethingTemplate2(T && vec)
{
    doSomething(std::forward<T>(vec));
}


int main()
{
    CustomVector my_vec(10, 1024);
    
    CustomVector temp1(my_vec);
    cout << my_vec.n_data << endl;
    cout << endl;
    
    CustomVector temp2(std::move(my_vec));  // move : 생성자를 호출할때 move construct로 부르겠다는 의미(바궈준다 ㄴㄴ)
    cout << my_vec.n_data << endl;
    cout << endl;
    
    
    doSomething(my_vec);
//    doSomething(std::move(my_vec));   // 이렇게도 사용하여 강제로 R-value로 사용 할 순 있지만 권장x,
                                        // 프로그래머가 뒤에서 my_vec을 사용하지 않을것이라는 걸 외우고 있어야함
    doSomething(CustomVector(10, 8));
    
    
    cout << endl;
    CustomVector my_vec1(10, 1024);
    
    doSomethingTemplate1(my_vec1);
    doSomethingTemplate2(CustomVector(10, 9));
        
    
    return 0;
}
