#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// 중요 모드!!! debug모드랑 release모드에서 속도차이가 매우 크기 때문에! 프로그램을 만들어서 실제 시간을 알고싶을때는
// 모드를 바꿔서 실행해봐야한다. 또한 실행속도는 여러 환경에 따라 달라지기 때문에 제어하기가 쉽지 않음!
// 따라서 출력 되는 시간을 너무 신봉해서 매달리지말고, 여러환경에서 여러번 돌려보고 생각하는것이 좋음!

using namespace std;

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;
    
    std::chrono::time_point<clock_t> start_time = clock_t::now();
    
public:
    void elapsed()
    {
        std::chrono::time_point<clock_t> end_time = clock_t::now();
        
        cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
    }
};


int main()
{
    random_device rnd_device;
    mt19937 mersenne_engine{ rnd_device() };
    
    vector<int> vec(100000);
    for(unsigned int i = 0; i < vec.size(); ++i)
    {
        vec[i] = i;
    }
    
    std::shuffle(begin(vec), end(vec), mersenne_engine);
    
//    for (auto &e : vec) cout << e << " ";
    cout << endl;
    
    Timer timer;
    
    std::sort(begin(vec), end(vec));
    
    timer.elapsed();
    
//    for (auto &e : vec) coutC << e << " ";
    cout << endl;
    
    return 0;
}
