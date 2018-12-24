#include<iostream>
using namespace std;
int main(){
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m,cnt = 0,d,x = 6;
	for(y = 2000; y <= 2100; y++){
		for(m = 0; m < 12; m++){
			if(m == 1 && y%4 == 0 &&  y%100!=0 || y%400 == 0)month[1]++;
			for(d = 1; d <= month[m]; d++,x++){
				if(x == 8)x = 1;
				if(m == 2 && d == 4 && x == 6){
				//	cout << y <<"/"<<m+1<<"/"<<d <<'/'<<x<<endl; 
				cnt++;
				}
			}
			if(m == 2 && y%4 == 0 && y%100!=0 || y%400 == 0 )month[1]--;
		}
	}
	cout << cnt;
	return 0;
}
