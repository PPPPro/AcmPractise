#include<iostream>
#include<cmath>
#include<set> 
#include<vector>
using namespace std;
const int Max = 8000010;
bool vis[Max];
void is_prime(int n){
	int i,j;
	for(i = 0; i <= n; i++)
		vis[i] = 1;
		
	for(i = 2; i*i <= n; i++){
		if(vis[i]){
			for(j = i*2; j <= n; j+=i){
				vis[j] = 0;
			}
		}
		
	}
}
int main(){
	int n,i,cnt = 0;
	cin >> n;
	is_prime(n);
	for(i = 2; i <= n/2; i++){
		if(vis[i]&&vis[n-i])cnt++;
	}
	//if(a.count(n/2))cnt++;
	cout<<cnt;
}
