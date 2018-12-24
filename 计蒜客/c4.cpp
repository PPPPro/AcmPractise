#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[110][110],b[110][110] = {0};

int main(){
	int i,j,n,tmp,ans = 0;
	cin >> n;
	for (i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            cin >> a[i][j];
        }
	}
	for (i = 1; i < n; i++){
        for(j = 0; j <= i; j++){
            if(j == 0)a[i][j] += a[i-1][j];
            else if(j == i)a[i][j] += a[i-1][j-1];
            else{
            int tmp1 = a[i-1][j-1]+a[i][j];
            int tmp2 = a[i-1][j]+a[i][j];
            a[i][j] = max(tmp1,tmp2);
            }

        }
	}
	int z = 0;
    for(j = 0; j < n; j++){
        if( a[n-1][j] > z)z =  a[n-1][j];
    }
    cout << z;

	return 0;
}
