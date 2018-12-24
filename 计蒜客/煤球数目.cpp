#include<iostream>
using namespace std;
int main(){
	int ans = 0;
	for(int i = 1; i <= 100; i++)
		ans += i *(i+1) /2;
	cout << ans;
} 
