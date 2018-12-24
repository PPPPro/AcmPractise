#include <iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int tot = 0;
int Max_res = 0;
int n = 8;
bool x[20],y[20],a[20];
int e[9][9];
void f(int deep,int res){
    int i,ok = 1;
    if( deep >= n) {
    	tot++;
    	if(res>Max_res)
    	Max_res = res;
    	return;
	}
        for(i = 0; i < n; i++){ 
           if(x[i+deep] == false && y[i - deep + n ] == false&&a[i] == false){
        	x[i+deep] = true;
        	y[i - deep + n] = true;
        	a[i] = true;
        	res += e[deep][i];
        	f(deep+1,res);
        	res -= e[deep][i];
        	a[i] = false;
        	x[i+deep] = false;
        	y[i - deep + n] = false;	
           }
        }
    
}
int main(){
	int i,j,tmp,ans = 0;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			cin >> e[i][j];
		}
	}
	memset(x,false,sizeof(x));
	memset(y,false,sizeof(y));
	memset(a,false,sizeof(a));
	f(0,0);
	cout << Max_res;
	return 0;
}

