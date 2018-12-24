#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge{
    int v,next;
}E[MAX_M];      
int p[MAX_N],eid,root;
bool is_root[MAX_N]; //����ڵ� 
void init(){//�ڽӱ��ʼ�� 
    memset(p,-1,sizeof(p));
    eid = 0;
}

void insert(int u,int v){//�ڽӱ� 
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int d[MAX_N],fa[MAX_N][20];
// ���ڵ�����  
// fa[i][j] i�ڵ��2^j���� 


void dfs(int u){//��ʼ�����d[],��fa[i][0]���������׽ڵ�2^0 = 1; 
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
//lca�����㷨 
int lca(int x,int y){
    int i,j;
    if(d[x] < d[y]){//ȷ��x����ȱ�y�� 
        swap(x,y);
    }
    //��x������ֱ��x����Ⱥ�yһ�� 
    for(i = 0; (1 << i) <= d[x]; i++);
    i--;//�ҳ���i�����Ŀ�����Ҫ��d[x]���ȥ
	//��2^i,Ҳ���ǣ�i������2^i <= d[x]�����ֵ 
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
    for(int i = 0; i < n-1; i++){//�����ڽӱ� 
        int u ,v;
        cin >> u >> v;
        insert(u,v);
        insert(v,u);
        is_root[v] = 1;//������Ǹ��ڵ���Ϊ1 
    }
    memset(d,-1,sizeof(d));//��ʼ��d 
    
    //�Ҹ��ڵ� 
    for(int i = 1; i <= n; i++){
    	if(!is_root[i])root = i;
    }
    d[root] = 0;
    //��d��ֵΪ��� d[i] = j .i�ڵ�������j 
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
