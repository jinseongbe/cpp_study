#include <iostream>

using namespace std;
// class안에 nested 시키기 전
enum FruitType
{
    APPLE, BANANA, CHERRY,
};

class Fruit
{
private:
    FruitType m_type;
    
public:
    Fruit(FruitType type)
    : m_type(type)
    {}
    
    FruitType getType()
    {
        return m_type;
    }
};

// class안에 nested 시킨 후(nested types)
class Fruit_nestedType
{
public:
    enum FruitType2
    {
        APPLE, BANANA, CHERRY,
    };
    
    /* 기타 등등 여러가지를 넣을 수 있으므로, 해당 class 안에서만 사용하는 특정 자료형의 경우 이런식으로 쓰면 좋다!
    enum class fruit1
    {
        
    };
    
    class InnerClass
    {
        
    };
    
    struct InnerClass
    {
        
    };
    */
private:
    FruitType2 m_type;
    
public:
    Fruit_nestedType(FruitType2 type)
    : m_type(type)
    {}
    
    FruitType2 getType()
    {
        return m_type;
    }
};



int main()
{
    Fruit apple(APPLE);
    
    if (apple.getType() == APPLE)
    {
        cout << "APPLE" << endl;
    }
    
    
    Fruit_nestedType banana(Fruit_nestedType::BANANA);
    
    if (banana.getType() == Fruit_nestedType::BANANA)
    {
        cout << "BANANA" << endl;
    }
    
    return 0;
}
