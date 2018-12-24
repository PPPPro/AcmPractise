#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int gcd(int a, int b){
    if(a < b){
        int temp;
        temp = a;
        a = b;
        b = temp;
        }
    while(a % b){
        int r = a % b;
        b = r;
        r = a % b;
    }
return b;
}

int f(int n,int m){

}
int main(){
	int i,j,n,tmp,res,ans = 0;
	int a,b,c;
	cin >> a >> b >> c;
	tmp = a*b/gcd(a,b);
	res = c*tmp/gcd(c,tmp);
    cout << res;
	return 0;
}
