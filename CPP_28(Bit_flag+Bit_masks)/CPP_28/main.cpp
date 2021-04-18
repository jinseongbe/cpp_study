#include <iostream>
#include <bitset>

int main()
{
    using namespace std;
    
    /* 아이템의 유무를 저장하기 위하여 변수를 다 만드는것은 불합리적
    bool item1_flag = false;
    bool item2_flag = false;
    bool item3_flag = false;
    bool item4_flag = false;
    */
    
    // Bit flag
    const unsigned char opt0 = 1 << 0;
    const unsigned char opt1 = 1 << 1;
    const unsigned char opt2 = 1 << 2;
    const unsigned char opt3 = 1 << 3;
    cout << bitset<8>(opt0) << endl;
    cout << bitset<8>(opt1) << endl;
    cout << bitset<8>(opt2) << endl;
    cout << bitset<8>(opt3) << endl << endl;
    
    unsigned char items_flag = 0;
    cout << "No item\t\t\t\t"<< bitset<8>(items_flag) << endl;
    
    // event item0 on
    items_flag |= opt0;
    cout << "Item0 obtained\t\t" << bitset<8>(items_flag) << endl;
    
    // event item3 on
    items_flag |= opt3;
    cout << "Item3 obtained\t\t" << bitset<8>(items_flag) << endl;
    
    // event item3 lost
    items_flag &= ~opt3;
    cout << "Item3 lost\t\t\t" << bitset<8>(items_flag) << endl;
    
    // has item1 ?
    if (items_flag & opt1) {cout << "Has Item1 " << endl;}
    else {cout << "Don't has Item1" << endl;}
    
    // has item0 ?
    if (items_flag & opt0) {cout << "Has Item0 " << endl;}
    else {cout << "Don't has Item0" << endl;}
    
    // obtain item 2,3
    items_flag |= (opt2 | opt3);
    cout << bitset<8>(opt2 | opt3) << endl;
    cout << "Item2,3 obtained \t" << bitset<8>(items_flag) << endl;
    
    //lost item2, obtain item1
    if ((items_flag & opt2) && !(items_flag & opt1))
    {
        cout << std::bitset<8>(items_flag) << endl;
        items_flag ^= (opt2 | opt1);
        cout << std::bitset<8>(items_flag) << endl << endl << endl;
    }
    
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) 이런쪽에서도 사용함
    
    
    //Bit masks
    unsigned int pixel_color = 0xDAA520;
    unsigned char red, green, blue;
    cout << "pixel_color\t:\t" << std::bitset<32>(pixel_color) << endl << endl;
    
    const unsigned int red_mask = 0xFF0000;
    const unsigned int green_mask = 0x00FF00;
    const unsigned int blue_mask = 0x0000FF;
    cout << "red_mask\t:\t" << std::bitset<32>(red_mask) << endl;
    cout << "green_mask\t:\t" << std::bitset<32>(green_mask) << endl;
    cout << "blue_mask\t:\t" << std::bitset<32>(blue_mask) << endl << endl;
    
    blue = pixel_color & blue_mask;
    cout << "blue\t:\t" << std::bitset<8>(blue) << endl;
    red = (pixel_color & red_mask) >> 16;
    cout << "red\t\t:\t" << std::bitset<8>(red) << endl;
    green = (pixel_color & green_mask) >>8;
    cout << "green\t:\t" << std::bitset<8>(green) << endl;
    
    return 0;
}
