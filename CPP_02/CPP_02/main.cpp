#include <iostream>
using namespace std;

int main()
{
    int pointAx, pointAy, pointBx, pointBy, pointCx, pointCy, pointDx, pointDy;
    
    cin >> pointAx >> pointAy;
    cin >> pointBx >> pointBy;
    cin >> pointCx >> pointCy;
    
    if (pointAx == pointBx)
    {
        pointDx = pointCx;
    }
    else if (pointAx == pointCx)
    {
        pointDx = pointBx;
    }
    else
    {
        pointDx = pointAx;
    }

    
    if (pointAy == pointBy)
    {
        pointDy = pointCy;
    }
    else if (pointAy == pointCy)
    {
        pointDy = pointBy;
    }
    else
    {
        pointDy = pointAy;
    }
    
    cout <<pointDx<<" "<<pointDy<<endl;
    return 0;
}
