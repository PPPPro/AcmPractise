#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
const int MAX_N = 110;

struct road{
	int u,v,len;
};

std::vector<road> v;
int n,ans = 0;
int map[MAX_N][MAX_N];
int father[MAX_N];

bool cmp(road a,road b){
	return a.len < b.len;
}

/////²¢²é¼¯ //// 
void init(){
	std::memset(map,0,sizeof(map));
	for(int i = 0; i <= n; i++){
		father[i] = i;
	}
}
int find(int s){
	if(father[s] == s)return s;
	return father[s] = find(father[s]);
}
void merge(int a,int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		father[a] = b;
	}
}

int main(){
	
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			road tmp;
			std::cin >> tmp.len;
			tmp.u = i;
			tmp.v = j;;
			if(tmp.len ) 
			v.push_back(tmp);  
		}
	}
	
	std::sort(v.begin(),v.end(),cmp);
//	for(int i = 0; i < v.size(); i++){
//		std::cout <<v[i].u <<" " <<v[i].v<<" "<<v[i].len << std::endl; 
//	}std::cout << std::endl;
	init();
	for(int i = 0; i < v.size(); i++){
		if(find(v[i].u) == find(v[i].v)){
//			std:: cout << "continue" << std::endl;
//			std::cout << find(v[i].u )<< " " << find(v[i].v)<<std::endl;
			continue;
		}
		else{
//			std::cout << "merge" << std::endl;
			merge(v[i].u,v[i].v);
			ans += v[i].len;
		}
	}
	std::cout << ans; 
}
