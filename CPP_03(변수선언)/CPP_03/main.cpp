#include <iostream> // Input Output Stream

int main()
{
    /*
    int x = 123;// initialization
    int y(123);// initialization
    x = 123;// assignment operater
    
    std::cout << x << std::endl;

    // 메모리 할당 주소 확인
    std::cout << &x << std::endl;
    */
    
    int x = 1;
    x = x + 2;
    std::cout << x << std::endl; //3
    
    int y = x;
    std::cout << y << std::endl; //3
    
    std::cout << x + y << std::endl; //6
    
    std::cout << x << std::endl; //3
    
    int z;
    std::cout << z << std::endl; //?
    
    return 0;
}
 
