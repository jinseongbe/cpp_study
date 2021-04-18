#include <iostream>

int main()
{
    using namespace std;
    
    int hour(0);
    int min(0);
    
    cin >> hour >> min;
    
    min = min - 45;
    
    if (min < 0)
    {
        min = min + 60;
        hour = hour - 1;
        
        if (hour < 0)
        {
            hour = hour + 24;
        }
    }
    
    cout << hour << " " << min << endl;
    
    return 0;
}
