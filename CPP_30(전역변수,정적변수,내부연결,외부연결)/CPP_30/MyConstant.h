#pragma

//에러메세지가 나오지 않으면서도 안좋은 사례!

namespace Constants // 전역상수를 많이 사용함
{

    //const double pi(3.141592);
    //const double gravity(9.8);

    // MyConstants.cpp파일에서 초기화 해주고 여기선 선언만함
    extern const double pi;
    extern const double gravity;
}
