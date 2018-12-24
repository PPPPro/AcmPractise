#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<queue>
#include<vector>
using namespace std;
const int Max_N = 100;
const int Max_M = 10010;
const int inf = 0x3f3f3f3f;
int n,m;
bool inq[Max_N];
int E[Max_N];

struct road{
	int v;
	int len;
};

vector< vector<road> > v(Max_N);

void spfa(int s){
	memset(inq,false,sizeof(inq));
	memset(E,inf,sizeof(E));
	queue<int> q;
	q.push(s);
	E[s] = 0;
	inq[s] = true;
	while(!q.empty()){
		int ss;
		ss = q.front();
		q.pop();
		inq[ss] = false;
		for(int i = 0; i < v[ss].size(); i++){
			road tmp = v[ss][i];
			if(E[ss]+tmp.len < E[tmp.v]){
				E[tmp.v] = E[ss]+tmp.len;
				if(!inq[tmp.v]){
					inq[tmp.v] = true;
					q.push(tmp.v);
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
