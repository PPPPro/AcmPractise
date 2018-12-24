#include<iostream>
using namespace std;
int n,m,c_x,c_y,cnt = 0;
int a[30][30];
long long f[30][30];
int m_x[8] = {-2,-1,1,2,-2,-1,1,2};
int m_y[8] = {1,2,2,1,-1,-2,-2,-1};
void h(int x,int y){
	int i,j;
	for(i = 0; i <= n; i++){
		for( j  = 0; j <= m; j++){
			a[i][j] = 0;
		}
	}
	a[c_x][c_y] = 1; 
	for(i = 0; i < 8; i++){
		if(x+m_x[i] >=0 && y+m_y[i] >= 0 && x+m_x[i] <= n &&y+m_y[i]<=m)
		a[x+m_x[i]][y+m_y[i]] = 1;
	}
}
void d(){
	f[0][0] = 1;
	for (int i = 0;i <= n; ++i) {
	    for (int j = 0; j <= m; ++j) {
	    	if(a[i][j] == 1){
	    		continue;
	    	}
	        if (i != 0 && a[i][j] == 0) {
	            f[i][j] = f[i][j] + f[i-1][j];
	        }
	        if (j != 0 && a[i][j] == 0) {
	            f[i][j] = f[i][j] + f[i][j-1];
	        }
	    }
	}
}
int main(){
	int i,j;
	for(i = 0; i < 30; i++){
		for( j= 0; j < 30; j++){
			f[i][j] = 0;
		}
	}
	cin >> n >> m >> c_x >> c_y;
	h(c_x,c_y);
	d();
	cout << f[n][m];
	return 0;
}
