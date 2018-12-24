#include<iostream>
#include<queue>
#include<cctype> 
#include<cstring> 
using namespace std;
const int Max = 5010;
int step[Max],n,A,B;
struct point{
	int x;
	int s;
	point(int xx,int ss){
		x = xx;
		s = ss;
	}
};
int main(){
	bool vis[Max];
	memset(vis,0,sizeof(vis));
	cin >> n >> A >> B;
	queue<point> q;
	q.push(point(A,0));
	while(!q.empty()){
		point tmp = q.front();
		//cout<< tmp.x<<" "<<tmp.s<<endl;
		if(tmp.x == B){
			cout << tmp.s;
			return 0;
		}
		else{
			 if(tmp.x+1<=n &&!vis[tmp.x+1]){
			 	q.push(point(tmp.x+1,tmp.s+1));
			 	vis[tmp.x+1] = 1;
			 }
			 if(tmp.x-1 >= 0 && !vis[tmp.x-1]){
			 	q.push(point(tmp.x-1,tmp.s+1));
			 	vis[tmp.x-1] = 1;
			 }
			 if(tmp.x*2 <= n &&!vis[tmp.x*2]){
			 	q.push(point(tmp.x*2,tmp.s+1));
			 	vis[tmp.x*2] = 1;
			 }
		}
		q.pop();
	}
	return 0;
} 
