#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int a1 = 0,a2 = 0,a3 = 0,a5 = 0;
	float a4 = 0;
/////////
	for(int i = 0; i < n; i++)
		if(a[i]%5 == 0 && a[i]%2 == 0)a1 += a[i];
	
////////
	int cnt = 0;
	int b[n];
	for(int i = 0; i < n; i++){
		if(a[i]%5 == 1){
			b[cnt++] = a[i];
		}
	}
	int key = 1;
	for(int i = 0; i < cnt; i++){
		a2 += b[i]*key;
		key = key * (-1);
	}
////////
	for(int i = 0; i < n; i++){
		if(a[i] % 5 == 2){
			a3++;
		}
	}
	cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 5 == 3){
			cnt++;
			a4+=a[i];
		}
	}
	a4 = a4/cnt;

///////
	for(int i = 0; i < n; i++){
		if(a[i]%5 == 4){
			a5 = max(a5,a[i]);
		}
	}
	if(a1 != 0)
	printf("%d ",a1);
	else{cout<<"N ";}
	if(a2 != 0)
	printf("%d ",a2);
	else{cout<<"N ";}
	if(a3 != 0)
	printf("%d ",a3);
	else{cout<<"N ";}
	if(a4 > 0)
	printf("%.1f ",a4);
	else{cout<<"N ";}
	if(a5 != 0)
	printf("%d",a5);else{cout<<"N";}
	return 0;
}