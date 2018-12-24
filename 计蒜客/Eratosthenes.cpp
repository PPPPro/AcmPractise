#include<iostream>
#include<cmath>
using namespace std;
const int Max = 1000;
int a[Max];
void is_prime(int n){
	int i,j;
	for(i = 0; i <= n; i++)
		a[i] = 1;
	for(i = 2; i < sqrt(n); i++){
		for(j = i*i; j <= n; j+=i){
			a[j] = 0;
		}
	}
}
int main(){
	int n,i,res = 0;
	cin >> n;
	is_prime(n);
	for(i = 2; i <= n; i++){
		if(a[i])
		res += i;
	}
	cout << res;
	return 0;
} 
