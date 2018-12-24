//p27,p30(1)

#define LOCAL
#include<cstdio>
#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define INF 1000000000
int main(){
    #ifdef LOCAL;
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    #endif // LOCAL
    int x, n = 0,min = INF, max = -INF, s = 0;
    while(cin >> x){
        s += x;
        if(x < min) min = x;
        if(x > max) max = x;
        n++;
    }
    cout << min << " " << max <<" "<<(double)s/n;
    return 0;
}
