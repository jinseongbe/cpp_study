#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
    typedef double  distance_t;
    
    double          my_distanace;
    distance_t      home2work;   // 컴파일러입장에서는 똑같이 더블로 인식함
    distance_t      home2school; // 사용자의 편의를 위해서 사용하는것임!
    
    typedef vector<pair<string, int>> pairlist_t;
    
    pairlist_t pairlist1;
    pairlist_t pairlist2; // 이런식으로 복잡한 자료형도 편하게 사용 할 수 있음
    
    
    using pairlist_tt = vector<pair<string, int>>; // 이런식으로 사용 할 수도 있지만 내부적으로는 아주 다름!
    pairlist_tt pairlist3;
    pairlist_tt pairlist4;
    
    return 0;
}
