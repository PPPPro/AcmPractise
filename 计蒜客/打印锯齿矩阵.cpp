#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iterator>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){

    vector<int> vec[10005];
	int i,j,n,m,tmp,ans = 0,x,y;
	cin >> n >> m;
	for( i = 0; i < m; i++){
        cin >> x >> y;
        vec[x].push_back(y);
	}
	for( i = 1; i <= n; i++){
        for(j = 0; j < vec[i].size(); j++){
            if(j != (vec[i].size()-1))
            cout<< vec[i][j]<<" ";
            else
                cout<< vec[i][j];
        }
        if(i < n)cout<<endl;
	}
	return 0;
}
