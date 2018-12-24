#include<iostream>
#include<algorithm>
using namespace std;
const int Max_N = 1005;
int father[Max_N],n,m;
void init(){ 
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
}
int get(int s){
	if(father[s] == s)
		return s;
	return get(father[s]);
}
int main(){
	while((cin >> n >> m)!=0){
		int cnt = 0;
		init();
		for(int i = 0; i < m; i++){
			int u,v;
			cin >> u >> v;
			u = get(u);
			v = get(v);
			if(u != v){
				father[u] = v;
			}
		}
		for(int i = 1; i <= n; i++){
			if(father[i] == i){
				cnt++;
			}
		}
			cout << cnt;
		}
	return 0;
} 
