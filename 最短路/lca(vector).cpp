#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int MAX_N = 100000;
const int MAX_M = 1000000;

vector< vector<int> >Roads(MAX_N);

int root;
bool is_root[MAX_N];
int d[MAX_N];
int fa[MAX_N][20];

void dfs(int u){
	for(int i = 0; i < Roads[u].size(); i++){
		if(d[Roads[u][i]] == -1){
			d[Roads[u][i]] = d[u] + 1;
			fa[Roads[u][i]][0] = u;
			dfs(Roads[u][i]);
		}
	}
}

void insert(int u,int v){
	Roads[u].push_back(v);
}

int lca(int x,int y){
	int i,j;
	if(d[x] < d[y]){
		swap(x,y);
	}
	
	for(i = 0; (1 << i) <= d[x]; i++);
	i--;
	
	for(j = i; j >= 0; j--){
		if(d[x] - (1 << j) >= d[y]){
			x = fa[x][j];
		}
	}
	if( x == y){
		return x;
	}
	for(j = i; j >= 0; j--){
		if(fa[x][j] != fa[y][j]){
			x = fa[x][j];
			y = fa[y][j];
		}
	}
	return fa[x][0];
}

int main(){
	int n;
	cin >> n;
	
	memset(is_root,0,sizeof(is_root));
	for(int i = 0; i < n-1; i++){
		int u ,v;
		cin >> u >> v;
		insert(u,v);
		insert(v,u);
		is_root[v] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(!is_root[i]){
			root = i;
			break;
		} 
	} 
	memset(d,-1,sizeof(d));
	d[root] = 1;
	dfs(root);
	for(int level = 1; (1 << level) <= n; level++){
		for(int i = 1; i <= n; i++){
			fa[i][level] = fa[fa[i][level-1]][level-1];
		}
	}
	
	int cnt;
	cin >> cnt;
	while(cnt--){
		int a,b;
		cin >> a >> b;
		cout << lca(a,b) << endl;
	}
	return 0;
} 
