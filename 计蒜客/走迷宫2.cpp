#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
char a[105][105];
int step[105][105];//记录步数 
bool vis[105][105] = {0};//标记 
int m_x[4] = {1,0,0,-1};
int m_y[4] = {0,-1,1,0};
struct point{
	int x,y;
	point(int xx,int yy){
		x = xx;
		y = yy;
	}
};
void bfs(int x,int y){
	queue<point> q;
	q.push(point(x,y));
	vis[x][y] = 1;
	while(!q.empty()){
		point tmp = q.front();
		q.pop();
	//	cout << tmp.x <<" TMP "<<tmp.y<<endl;
		for(int i = 0; i < 4; i++){
			int tx = tmp.x+m_x[i];
			int ty = tmp.y+m_y[i];
		//	cout << xx <<" " << yy<<endl; 
			if((tx >= 0&& tx < n) && (ty >= 0 && ty < m)&&
			vis[tx][ty] == 0 && (a[tx][ty] == '.'|| a[tx][ty] == 'T')){
				q.push(point(tx,ty));
				vis[tx][ty] = 1;
				step[tx][ty] = step[tmp.x][tmp.y] + 1;
				
			}
		}
	}
	return;
}
int main(){
	memset(vis,0,sizeof(vis));
	int i,j;
	int S_i,S_j,T_i,T_j;
	cin >> n >> m;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'S'){
				S_i = i;
				S_j = j;
			}
			if(a[i][j] == 'T'){
				T_i = i;
				T_j = j;
			}
		}
	bfs(S_i,S_j);
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			cout<< step[i][j]<<" ";
		}
		cout << endl;
	}
			
//	cout << step[T_i][T_j];
	return 0;
} 
