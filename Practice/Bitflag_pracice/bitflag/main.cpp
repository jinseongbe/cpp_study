#include <iostream>
#include <bitset>


int main()
{
    using namespace std;
    
    unsigned char option_viewed = 0x01;
    unsigned char option_edited = 0x02;
    unsigned char option_liked = 0x04;
    unsigned char option_shared = 0x08;
    unsigned char option_deleted = 0x80;
    unsigned char my_article_flags = 0;
    unsigned char flags = 0;
    
    cout << "viewed\t\t\t" << bitset<8>(option_viewed) << endl;
    cout << "edited\t\t\t" <<  bitset<8>(option_edited) << endl;
    cout << "liked\t\t\t" << bitset<8>(option_liked) << endl;
    cout << "shared\t\t\t" << bitset<8>(option_shared) << endl;
    cout << "deleted\t\t\t" << bitset<8>(option_deleted) << endl << endl;
    
    
    // option_viewed on
    my_article_flags |= option_viewed;
    
    // option_liked on
    my_article_flags |= option_liked;
    
    // option_liked again
    my_article_flags ^= option_liked;
    
    // option_deleted on
    my_article_flags |= option_deleted;
    
    cout << "Article_flags\t" << bitset<8>(my_article_flags) << endl << endl << endl;
    cout << "flags\t\t" << bitset<8>(flags) << endl << endl;
    flags |= ~(option_deleted | option_liked);
    cout << "flags\t\t" << bitset<8>(flags) << endl << endl;
    flags |= ~option_deleted & ~option_liked;
    cout << "flags\t\t" << bitset<8>(flags) << endl << endl;
    return 0;
}


// 80 162
