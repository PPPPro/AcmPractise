#include<iostream>
using namespace std;
int n,m;
int a[55][55] = {0};
long long f(int nn,int mm){
}
int main(){
	int i,j;
	
	cin >> n >> m;
	for(i = 0; i < n; i++){
			a[i][0] = 1;
			a[i][i] = 1;
	}
	for(i = 2; i < n; i++){
		for(j = 1; j < i; j++){
			a[i][j] = a[i-1][j-1]+a[i-1][j];
		}
	}
	cout << a[n-1][m-1];
	return 0;
}
