#include <iostream>
//#include <cstdint> // iostream에 내장되어있어서 중복으로 쓸필요는 없음

int main()
{
    using namespace std;
    
    std::int16_t i(5); // 16bit(2byte) 타입으로 바꿔주는것
    std::int8_t myint = 65; // char가 됨, 오류의 위험이 있음
    
    cout << myint << endl;
    
    std::int_fast8_t fi(5); // 8bits에서 제일 빠른 데이터 타입
    std::int_least64_t fl(5); // 적어도 64bits를 가지는 데이터 타입
    
    return 0;
}
