#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int Max = 105;
const int inf = 0x3f3f3f3f;
struct road{
	int v;
	int len;
};
int n,m;
bool inq[Max];
vector< vector<road> > v(Max);
int E[Max];
int spfa(int s){
	memset(inq,false,sizeof(inq));
	memset(E,inf,sizeof(E));
	queue<int> q;
	E[s] = 0;
	inq[s] = true;
	q.push(s);
	while(!q.empty()){
		int u;
		u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = 0; i < v[u].size(); i++){
			int t = v[u][i].v;
			if(E[u] + v[u][i].len < E[i]){
				E[i] = E[u] + v[u][i].len;
				if(!inq[t]){
					q.push(t);
					inq[t] = true;
				}
			}
		} 
	}
}
 
int main(){
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		road tmp;
		int u;
		cin >> u >> tmp.v >> tmp.len;
		v[u].push_back(tmp);
		v[u].push_back(tmp);
	}
	
	spfa(1);
	cout << endl;
	for(int i = 1; i <= n; i++){
		cout << E[i] << " ";
	}
	return 0;
} 

