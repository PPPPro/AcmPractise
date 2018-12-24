#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int Max = 1005;
vector< vector<int> > map(Max);

bool inq[Max];
bool have[Max];
int n;
int main(){
	memset(have,0,sizeof(have));
	int cnt = 0;
	int all = 0;
	memset(inq,0,sizeof(inq));
	cin >> n;
	for(int i = 0; i < n; i++){
		
		int u,v;
		cin >> u >> v;
		if(!have[v]){
			have[v] = 1;
			all++;
		}
		if(!have[u]){
			have[u] = 1;
			all++;
		}
		
		if(u!=v)
		map[u].push_back(v);
	}
	
	for(int i = 1; i < map.size(); i++){
		for(int j = 0; j < map[i].size(); j++){
			int u = map[i][j];
			
			if(!inq[u] && have[u]){
		//		cout <<"["<<u<<endl;
				cnt++;
				inq[u] = 1;
			}
		}
	}
	cout << all-cnt;
} 
