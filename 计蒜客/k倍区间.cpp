#include<iostream>
using namespace std;
const int Max = 100000;
int main(){
	int n,k,a[Max],i,j,cnt = 0,l,tmp;
	cin >> n >> k;
	for(i = 1; i <= n; i++)
		cin >> a[i];
		
	for(i = 1; i <= n; i++){
		for(j = i; j <= n; j++){
		tmp = 0;
			for(l = 1; l <= n-j; l++){
				tmp += a[i];
			}
		if(a[i]%k == 0)cnt++;
		}
	}
	cout << cnt;
}
