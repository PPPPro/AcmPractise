#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int lcm(int n, int m){
    if(m == 0){
        return n;
    }
    lcm(m,n%m);
}

int main(){
	int i,j,n,m,tmp,ans = 0;
	cin >> n >> m;
	cout << n*m/lcm(n,m);
	return 0;
}
