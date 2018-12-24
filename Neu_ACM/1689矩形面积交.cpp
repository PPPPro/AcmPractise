#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    double x1,x2,y1,y2;
    double x3,x4,y3,y4;
    double l1,r1,u1,d1;
    double res = 0;


    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    l1 = max(min(x1,x2),min(x3,x4));
    r1 = min(max(x1,x2),max(x3,x4));
    u1 = min(max(y1,y2),max(y3,y4));
    d1 = max(min(y1,y2),min(y3,y4));
    if(l1 < r1 && d1 < u1)
    {
        res = (r1-l1) * (u1-d1);
    }
    printf("%.2lf",res);
    
    return 0;

}
