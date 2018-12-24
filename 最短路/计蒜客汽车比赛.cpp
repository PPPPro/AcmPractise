#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int Max_N = 1005;
const int Max_M = 5005;
const int inf = 0x3f3f3f3f;
int n,m;
int G[Max_N][Max_N];
int dist[Max_M];
bool vst[Max_N];

void dijkstra(int s){
	memset(vst,false,sizeof(vst));
    memset(dist,0x3f,sizeof(dist));
    dist[s] = 0;
	    for(int i = 0; i < n; i++){
	        int v,min_d = inf;
	        for(int j = 1; j <= n; j++){
	            if(!vst[j] && dist[j] < min_d){
	                min_d = dist[j];
	            	v = j;
	            } 
	        }
	        
	        vst[v] = true;
		 
		 	for(int j = 1; j <= n; j++){
		 		dist[j] = min(dist[j],dist[v]+G[v][j]);
		 	}	
	    }

}
int main(){
    memset(G,0x3f,sizeof(G));//!!!!!!!!!!G初始化为无穷！！！！不是0 
	cin >> n >> m;
	for(int i = 0; i < m; i++){
        int u,v,len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }

	dijkstra(1);
	        cout << dist[n];
	
	return 0;
}
