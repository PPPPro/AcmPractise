#include<iostream>
#include<algorithm>
using namespace std;
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int cnt = 0;
void f(int y,int m,int d){
	if(y%4==0 && y%40==0 || y%100!=0)month[1]++;
	
	if(y<=2059&&y>=1960 ){
		if(m<=12){
			if(d<=month[m-1]){
				//cnt++;
				cout<<y<<'-';
				if(m<10)cout<<'0';
				cout<<m<<'-';
				if(d<10)cout<<'0';
				cout<<d<<endl;
			}
		}
	}
	if(y%4==0 && y%40==0 || y%100!=0)month[1]--;
	return;
}
int main(){
	int i,j,a,b,c,year;
	cin >> a >> b >> c;
	
	f(a+1900,b,c);
//	f(a+1900,c,b);
	
//	f(a+2000,c,b);
	f(c+1900,a,b);
	f(c+1900,b,a);
	f(a+2000,b,c);
	f(c+2000,b,a);
	f(c+2000,a,b);
	return 0;
}
