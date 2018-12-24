#include<iostream>
#include<algorithm>
const int MAX_N = 100;
const int MAX_M = 10010;
int n,m,ans = 0;
struct road{
	int u,v,len;
}E[MAX_M];

int cmp(road a,road b){
	return a.len < b.len;
}
////////////////////²¢²é¼¯ 
int father[MAX_N];
void init(){
	for(int i = 0; i < n; i++){
		father[i] = i;
	}
} 

int find(int s){
	if(father[s] == s)return s;
	return find(father[s]);
}

void merge(int a,int b){
	father[a] = b;
}
/////////////////////////
int main(){
	std::cin >> n >> m;
	for(int i = 0; i < m; i++){
		std::cin >> E[i].u >> E[i].v >> E[i].len;
	}
	std::sort(E,E+m,cmp);
	init(); 
	for(int i = 0; i < m; i++){
		if(find(E[i].v) == find(E[i].u)){
			continue;
		}
		else{
			std::cout << i << std::endl;
			merge(E[i].v,E[i].u);
			ans += E[i].len;
		}
	}
	
	std::cout << ans;
 
} 
