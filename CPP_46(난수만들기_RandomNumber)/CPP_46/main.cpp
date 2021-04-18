#include <iostream>
#include <cstdlib> // std::radn(), std::srand()
#include <ctime>   // std::time()
#include <random>

using namespace std;

unsigned int PRNG() // Pseude Random Number Generator
{
    static unsigned int seed = 5523; // seed number, 계속 바뀌어야 하기 때문에 static을 사용
    
    seed = 8253729 * seed + 2396403; // 오버플로우를 발생시켜서 난수를 사용한다
    
    return seed % 32768; // 최대 크기의 숫자로 나누어준다
}


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0); // RAND_MAX: 매크로로 정의되어 있는것으로 랜덤넘버로 나올 수 있는 가장 큰 숫자, 나누기가 느리기 때문에 상수로 만들어서 사용한것임!
    
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}



int main()
{
    for (int count = 1; count <= 100; ++count)
    {
        cout << PRNG() << "\t";
        
        if (count % 5 == 0) cout << endl;
    }
    cout << endl << endl;;
    
//    std::srand(5323); // 이 경우에는 반복실행했을 경우 같은 랜덤넘버가 생성됨, 디버깅할때는 seed고정을 해놓고 함!
    std::srand(static_cast<unsigned int>(std::time(0))); // 시간을 이용해서 seed number를 변경해줌
    for (int count = 1; count <= 100; ++count)
    {
        cout << std::rand() << "\t";
        
        if (count % 5 == 0) cout << endl;
    }
    cout << endl << endl;;

    
    //특정한 정수 사이에 랜덤넘버를 발생시키고 싶을 경우
    for (int count = 1; count <= 100; ++count)
    {
        cout << getRandomNumber(5, 8) << "\t";
        
        if (count % 5 == 0) cout << endl;
    }
    cout << endl << endl;;

    for (int count = 1; count <= 100; ++count)
    {
        cout << rand() % 4 + 5 << "\t"; // c스타일로, 정밀하거나 큰값으로 나누어 줄때는 별로 좋지 않은 방법
        
        if (count % 5 == 0) cout << endl;
    }
    cout << endl << endl;;

    
    // random 라이브러리 사용, 주로 이것을 사용하게 될 것임!
    std::random_device rd;
    std::mt19937 mesenne(rd());// 32bits(//mt19937_64: 64bits), creat a mesenne twister,
    std::uniform_int_distribution<> dice(1, 6);
    
    for (int count = 1; count <= 20; ++count)
        cout << dice(mesenne) << endl;
    
    return 0;
}
