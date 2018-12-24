#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
const int Max = 1e5;
int main(){
    int n,l1,r1,l2,r2;
    int a[Max];
    cin >> n>>l1>>r1>>l2>>r2;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a+l1-1,a+r1);
    sort(a+l2-1,a+r2,cmp);
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n-1)cout<<" ";
    }
    return 0;
}
