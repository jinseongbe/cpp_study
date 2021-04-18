#include <iostream>

using namespace std;

enum class Colors
{
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
};

void printColorName1(Colors color)
{
    if(color ==  Colors::BLACK)
        cout << "Black" << endl;
    else if (color == Colors::WHITE)
        cout << "White" << endl;
    //...
}

void printColorName2(Colors color)
{
    switch (color)
    {
        case Colors::BLACK :
            cout << "BLACK" << endl;
            break;
        case Colors::WHITE :
            cout << "WHITE" << endl;
            break;
        case Colors::RED :
            cout << "RED" << endl;
            break;
        case Colors::GREEN :
            cout << "GREEN" << endl;
            break;
        case Colors::BLUE :
            cout << "BLUE" << endl;
            break;
        default:
            break;
    }
}

void printColorName3(Colors color)
{
    switch (static_cast<int>(color))
    {
        case 0 :
            cout << "BLACK" << endl;
            break;
        case 1 :
            cout << "WHITE" << endl;
            break;
        case 2 :
            cout << "RED" << endl;
            break;
        case 3 :
            cout << "GREEN" << endl;
            break;
        case 4 :
            cout << "BLUE" << endl;
            break;
        default:
            break;
    }
}


int main()
{
    printColorName1(Colors::BLACK);
    printColorName2(Colors::BLACK);
    printColorName3(Colors::BLACK);
    
    int x;
    cin >> x;
    {
        switch (x)
        {
            case 0:
                cout << "zero";
            case 1:
                cout << "One";
                break; // break 사용안하면 해당하는것 이후로 모두 실행됨, 보통은 사용함
            case 2:
                cout << "Two";
        }
    }

    cout << endl << endl;
    
    int y;
    cin >> y;
    
    switch (y)
    {
        int a;
//        int b(2); // 변수를 선언할 순 있지만 대입은 해줄 수 없다! 명심!
            
        case 0:
//            int a;//  안에서 선언해도 밖에서 선어되는것처럼 작동된다! 위에 있는 int a 처럼, 그냥 스위치 문 밖에서 사용하고 중괄호로 감싸는것을 권장한다
        case 1:
        {
            int b; // case문 안에 중괄호를 만들어서 실행하면, 위 방법보다는 낫다, 사용되고 괄호를 나가면 없어짐
            cout << b + 1 << endl;
        }
        default:
            cout << "Undefined input " << endl;
            break; // 디폴트 밑에는 아무것도 없는게 보편적이라 break가 없어도 되지만 만약,혹시를 대비해 사용하기도 함, 취향차이
    }
    return 0;
}
