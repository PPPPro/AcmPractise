#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,k,n,m,tmp,ans = 0;
	cin >> n >> m;
	for(i = 0; i < n; i++){
        for(j = 0,k = 1; j <= m ; j++,k++){
            cout<<"+";
            if(k != m+1)cout<<"-";
        }
        cout<<endl;
        for(j = 0,k = 1; j <= m ; j++,k++){
            cout<<"|";
            if(k != m+1)cout<<"*";
        }
        cout<<endl;

	}
	for(j = 0,k = 1; j <= m ; j++,k++){
            cout<<"+";
            if(k != m+1)cout<<"-";
        }
	return 0;
}
