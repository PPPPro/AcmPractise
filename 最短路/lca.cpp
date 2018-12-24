#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge{
    int v,next;
}E[MAX_M];      
int p[MAX_N],eid,root;
bool is_root[MAX_N]; //存根节点 
void init(){//邻接表初始化 
    memset(p,-1,sizeof(p));
    eid = 0;
}

void insert(int u,int v){//邻接表 
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int d[MAX_N],fa[MAX_N][20];
// 各节点的深度  
// fa[i][j] i节点的2^j祖先 


void dfs(int u){//初始化深度d[],和fa[i][0]就是他父亲节点2^0 = 1; 
    for(int i = p[u]; i + 1; i = E[i].next){
        if(d[E[i].v] == -1){
        	cout << "in:"<< E[i].v << endl;
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
		else cout << "out:"<< E[i].v << endl;
    }
}
//lca倍增算法 
int lca(int x,int y){
    int i,j;
    if(d[x] < d[y]){//确保x的深度比y大 
        swap(x,y);
    }
    //让x向上找直到x的深度和y一致 
    for(i = 0; (1 << i) <= d[x]; i++);
    i--;//找出的i是最大的可能需要从d[x]里减去
	//的2^i,也就是，i是满足2^i <= d[x]的最大值 
    for(j = i; j >= 0; j--){
        if(d[x] - (1 << j) >= d[y]){
            x = fa[x][j];
        }
    }
    if(x == y){
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
int main() {
    int n;
    init();
    cin >> n;
    
    memset(is_root,0,sizeof(is_root));
    for(int i = 0; i < n-1; i++){//输入邻接表 
        int u ,v;
        cin >> u >> v;
        insert(u,v);
        insert(v,u);
        is_root[v] = 1;//如果不是根节点则为1 
    }
    memset(d,-1,sizeof(d));//初始化d 
    
    //找根节点 
    for(int i = 1; i <= n; i++){
    	if(!is_root[i])root = i;
    }
    d[root] = 0;
    //把d赋值为深度 d[i] = j .i节点的深度是j 
	dfs(root);
	 
    for(int level = 1; (1 << level) <= n; level++){
        for(int i = 1; i <= n; i++){
            fa[i][level] = fa[fa[i][level - 1]][level - 1];
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
