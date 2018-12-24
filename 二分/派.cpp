#include<iostream>
#include<cmath>
#define PI acos(-1.0)
#define eps 1e-8
using namespace std;
int n,f;
int a[10010];
bool j(double s){
    int cnt = 0;
    for(int i = 0; i < n;  i++){
        cnt += (int)(a[i]*a[i])/(s*s);
    }
    if(cnt >= f)return true;
    return false;
}
double bin_search(double l,double r){
    double mid;
    while(r-l > eps){
        mid = (l+r)/2;
        if(j(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    return mid;
}
int main(){
    cin >> n >> f;
    f++;
    double t;
    double CakeSize = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > CakeSize){
            CakeSize = a[i];
        }
    }
    double ans = bin_search(0,CakeSize);
    cout << ans*ans*PI << endl;
    return 0;
}
