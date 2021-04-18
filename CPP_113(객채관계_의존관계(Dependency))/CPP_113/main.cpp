#include "Worker.h" // Timer class의 선언이 Worker의 CPP파일에서만 선언되면 header에서 선언하지 않아도 사용가능함
                    // 보기에 아주 정리가 잘 되어보임
                    // 가장많이 사용하게 될 거임? 아마?

using namespace std;

int main()
{
    Worker worker;
    
    worker.doSomething();
    
    
    return 0;
}
