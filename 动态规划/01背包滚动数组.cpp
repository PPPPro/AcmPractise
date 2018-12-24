#include<iostream>
#include<cstdio>
#include<cstring>
const int Max = 12885;
const int Max_n = 3405;
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int i,j,n,V;
	int dp[Max];
	int v[Max_n],p[Max_n];
	cin >> n >> V;
	for(i = 1; i <= n; i++){
		cin >> v[i] >> p[i];
	}
	memset(dp,0,sizeof(dp));
	for(i = 1; i <= n; i++){
		for(j = V; j >= v[i]; j--){
				dp[j] = max(dp[j],dp[j-v[i]]+p[i]); 
		}
	}
	cout << dp[V] << endl;
	return 0;
}