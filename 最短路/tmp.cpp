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
	memset(inq,0,sizeof(inq));
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
			road tmp = v[u][i];
			if(E[u] + tmp.len < E[tmp.v]){
				E[tmp.v] = E[u] + tmp.len;
				if(!inq[tmp.v]){
					q.push(tmp.v);
					inq[tmp.v] = true;
				}
			}
		}
	}
}

int main(){

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u,tv,len;
		road tmp;
		cin >> u >> tv >> len;
		tmp.v = tv;
		tmp.len = len;
		v[u].push_back(tmp);
		tmp.v = u;
		v[tv].push_back(tmp);
	} 
	
	
	spfa(1);
	
	cout << endl;
	for(int i = 1; i <= n; i++){
		cout << E[i] << " ";
	}
	return 0;
} 

