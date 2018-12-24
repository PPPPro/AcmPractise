#include<iostream>
#include<algorithm>
using namespace std;
const int Max = 10005;
int n;
int father[Max] ;

void init(){
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
}

//带权并查集
void init1(){
	for(int i = 1; i <= n; i++){
		father[i] = i;
		dist[i] = 0;
		size[i] = 1;
	}
} 
//查找节点所在集合的根节点 
int get(int x){
	if(father[x] == x){
		return x;
	}
	return get(father[x]);
}

//带权并查集的查找
int get2(int x){
	if(father[x] == x){
		return x;
	}
	int y = father[x];
	father = get(y);
	dist[x] += dist[y];
	//x到根节点的距离等于x到之前父亲节点的距离加上
	//之前父亲节点到根节点的距离
	return father[x]; 
} 
//路径压缩  只关心每个节点的父节点，不关心树的真正结构
//在一次查询的时候，把路径上所有的点father[i]赋值为根节点
int get1(int x){
	if(father[x] == x){
		return x;
	}
	return father[x] = get(father[x]);
} 
//合并 
void merge(int x,int y){
	x = get(x);
	y = get(y);
	if(x != y){//这个判断是否多余 ？ 
		father[y] = x;
	}
} 

//带权合并
void merge(int a,int b){
	a = get(a);
	b = get(b);
	if(a != b){
		father[a] = b;
		dist[a] = size[b];
		size[b] += size[a];
	}
} 
int main(){
	
}
