#include<iostream>
#include<algorithm>
using namespace std;
	int a[1010][1010];
	int dp[1010][1010];
int main(){
	int n,i,j;
	cin >> n;
	for( i = 1; i <= n; i++){
		for( j = 1; j <= i; j++){
			cin >> a[i][j]; 
		}
	}
	dp[1][1] = a[1][1];
	for( i = 2; i <= n; i++){
		for( j = 1; j <= i; j++){
			if(j != 1 || j != i){
				int tmp1 = dp[i-1][j-1]+a[i][j];
				int tmp2 = dp[i-1][j]+a[i][j];
				dp[i][j] = max(tmp1,tmp2);
			}
			else if( j == 1 ){
				dp[i][j] = a[i-1][j];	
			}
			else if(j == i){
				dp[i][j] = a[i-1][j-1];
			}
		}
	}
	sort(dp[i-1],dp[i-1]+i);
	for( i = 1; i <= n; i++){
		for( j = 1; j <= i; j++){
			cout << dp[i][j]; 
		}
		cout << endl;
	}
	cout << dp[i-1][i-1];
	return 0; 
}
