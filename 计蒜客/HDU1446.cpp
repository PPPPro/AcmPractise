#include<iostream>
using namespace std;
int main(){
	int n,i,j;
	while(cin >> n){
		int sum = 0;
		for(i = 1; i < n; i++){
			sum += i;
		}
		cout << sum;
	}
}
