#include <iostream>

int main()
{
    using namespace std;
    
    int result(0);
    int year(0);
    
    cin >> year;
    
    if ((year % 4) == 0)
    {
       result = 1;
        
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        else
        {
            result = 1;
        }
    }
    else
    {
        result = 0;
    }
    
    cout << result << endl;
    
    return 0;
}
