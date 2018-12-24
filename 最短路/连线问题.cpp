#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAX_N = 110;
int n;
float ans = 0;
int x[MAX_N],y[MAX_N],father[MAX_N];
struct road{
	int u,v;
	float len;
};
vector <road> map;
bool cmp(road a,road b){
	return a.len < b.len;
}
void init(){
	for(int i = 1; i <= n; i++)
		father[i] = i;
}
int find(int s){
	if(father[s] == s)return s;
	return father[s] = find(father[s]);
}
void merge(int a,int b){
	int ta = find(a);
	int tb = find(b);
	father[ta] = tb;
}
int main(){
	cin >> n;
	init();
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 1; i <= n; i++){
	//	cout << i<<":  ";
		for(int j = 1; j <= n; j++){
			if(i == j)continue;
			float xx = (x[i]-x[j])*(x[i]-x[j]);
			float yy = (y[i]-y[j])*(y[i]-y[j]);
			road tmp;
			tmp.u = i;
			tmp.len = sqrt(xx+yy);
			tmp.v = j;
			map.push_back(tmp);
		}
	}
	
	sort(map.begin(),map.end(),cmp);
	
	for(int i = 0; i < map.size(); i++){
	//	cout << map[i].len << " "; 
		if(find(map[i].u) == find(map[i].v))continue;
		else{
	//		cout << map[i].len << "  " << map[i].u<<"   " << map[i].v<<endl; 
			merge(map[i].u,map[i].v);
			ans += map[i].len;
		}
	}
	printf("%f\n",ans);
	printf("%.2f",ans);
	return 0; 
} 
