#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std;
const int Max = 1005;
int n;
int G[Max][Max];
int main(){
	memset(G,0,sizeof(G));
	cin >> n;
	for(int i = 0; i < n; i++){
		int u,v;
		cin >> u >> v;
		G[u][v] = 1;
	}
	
	
}
