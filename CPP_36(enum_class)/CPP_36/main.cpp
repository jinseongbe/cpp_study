#include <iostream>

int main()
{
    using namespace std;
    
    enum Color
    {
        RED,
        BLUE,
    };
    
    enum Fruit
    {
        BANANA,
        APPLE,
    };
    
    Color color = RED;
    Fruit fruit = BANANA;
    
    if (color == fruit)  // enumd에서 integer로 바꾸기 때문에 둘다 0이라 실행됨
        cout << "Color is fruit ?" << endl;
    
    
    enum class Color2
    {
        RED,
        BLUE,
    };
    
    enum class Fruit2
    {
        BANANA,
        APPLE,
    };
    
    Color2 color2 = Color2::RED;
    Fruit2 fruit2 = Fruit2::BANANA;
    
//    if (color2 == fruit2)  // enumd class를 사용하여 비교가 안되게 만듬!
//    cout << "Color2 is fruit2 ?" << endl;
    
    if (static_cast<int>(color2) == static_cast<int>(fruit2))  // static으로 만들면 비교 가능하긴 하지만 이렇게 쓸일은 없을것이다!
    cout << "static_Color2 is static_fruit2 ?" << endl;
    
    return 0;
}
