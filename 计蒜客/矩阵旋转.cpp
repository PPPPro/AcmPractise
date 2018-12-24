#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,m;
	cin >> n >> m;
	int f[n][m];
	for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> f[i][j];
        }
	}
	for(i = 0; i < m; i++){
        for(j = n-1; j >= 0; j--){
            cout << f[j][i];
            if(j != 0)cout<<" ";
        }
        cout<<endl;
	}

	return 0;
}
