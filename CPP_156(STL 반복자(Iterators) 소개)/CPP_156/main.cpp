#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
    vector<int> container;
    for (int i = 0; i < 10; ++i)
        container.push_back(i);
    
    // 1.
//    vector<int>::iterator itr;
    vector<int>::const_iterator itr;
    itr = container.begin();
    while (itr != container.end())
    {
        cout << *itr << " ";
        
        ++itr;
    }
    cout << endl;
    
    // 2.
    for ( auto & e : container)
        cout << e << " ";
    cout << endl;
    
    // 3.
    for (auto itr = container.begin(); itr != container.end(); ++itr)
        cout << *itr << " ";
    
    cout << endl;
    
    // list도 동일한 방식으로 사용가능, 다만 다른 점들이 있으니 공부할것
    // set은 insert로만 고치면 똑같이 사용가능
    // map은 튜플을 사용해야 하기 때문에 여러가지 수정해줘야함
    
    
    return 0;
}
