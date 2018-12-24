#include <iostream>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,m,tmp,ans = 0;
	set<int> a;
	set<int> b;
	cin >> n >> m;
	for(i = 0; i < n; i++){
        cin >> tmp;
        a.insert(tmp);
	}
	for(i = 0; i < m; i++){
        cin >> tmp;
        a.insert(tmp);
	}
	for(set<int>::iterator it = a.begin(); it != a.end(); it++){
        cout<<*it;
        if(it != a.end()--)
            cout<<" ";
	}

	return 0;
}
