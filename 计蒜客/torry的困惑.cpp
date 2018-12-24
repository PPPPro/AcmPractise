#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> a;
void prime(int n){
	int i,j;
	for( i = 2; i <= n; i++){
		int tmp = 1;
		for( j = 2; j <= sqrt(i); j++){
			if( i%j == 0){
				tmp = 0;
			}
		}
		if(tmp)a.push_back(i);
	}
}
int main(){
	int n;
	long long res = 1;
	cin >> n;
	prime(100000);
	
	for(int i = 0; i < n; i++){
		res *= a[i];
	}
	
		res%=50000;
	cout << res;
	
}
