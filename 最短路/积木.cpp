#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int Max = 1e5+5;
int main(){
	int n,m;
	long long add = 0; 
	long long a[Max];
	memset(a,0,sizeof(a));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		int t;
		cin >> t;
		if(t == 1){
			int v,x;
			cin >> v >> x;
			a[v] = x-add;
		}
		else if(t == 2){
			int y;
			cin >> y; 
		 	add += y;
		}
		else if(t == 3){
			int q;
			cin >> q;
			cout <<"="<< a[q]+add << endl;
		}
	} 
	return 0;
}
