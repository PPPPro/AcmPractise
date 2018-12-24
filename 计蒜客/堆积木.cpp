#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
    vector<int> vec[10005];
	int i,j,n,m,a,b,tmp,ans = 0;
	cin >> n >> m;
	for(i = 1; i <= n; i++){
        vec[i].push_back(i);
	}


	for(i = 0; i < m; i++){

    vector<int> x;
        cin >> a >> b;
        if(a != b){
        for(j = 0; j < vec[b].size(); j++){
            vec[a].push_back(vec[b][j]);
            }
            vec[b].swap(x);
       }
	}



	for(i = 1; i <= n; i++){
        for(j = 0; j < vec[i].size(); j++){
            cout<<vec[i][j];
            if(j != vec[i].size()-1)cout<<" ";
        }
        cout<<endl;
	}

	return 0;
}
