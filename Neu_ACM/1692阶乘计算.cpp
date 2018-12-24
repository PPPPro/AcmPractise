#include<iostream>
#include<cstdio>
using namespace std;

typedef long long LL;
const int MAX_N = 100010;

int num[MAX_N],len;

void init(){
	len = 1;
	num[0] = 1;
}
 
int mult(int num[], int len, int n){
	LL tmp = 0;
	for(LL i = 0; i < len; i++){
		tmp = tmp + num[i] * n;
		num[i] = tmp % 10;
		tmp = tmp / 10;
	}
	while(tmp){
		num[len++] = tmp % 10;
		tmp = tmp / 10;
	}
	return len;
}
 
int main(){
	init();
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		len = (mult(num,len,i));
	}
	for(int i = len-1; i >= 0; i--){
		printf("%d",num[i]);
	}
	printf("\n");
	return 0;
} 
