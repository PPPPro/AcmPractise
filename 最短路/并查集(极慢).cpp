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

//��Ȩ���鼯
void init1(){
	for(int i = 1; i <= n; i++){
		father[i] = i;
		dist[i] = 0;
		size[i] = 1;
	}
} 
//���ҽڵ����ڼ��ϵĸ��ڵ� 
int get(int x){
	if(father[x] == x){
		return x;
	}
	return get(father[x]);
}

//��Ȩ���鼯�Ĳ���
int get2(int x){
	if(father[x] == x){
		return x;
	}
	int y = father[x];
	father = get(y);
	dist[x] += dist[y];
	//x�����ڵ�ľ������x��֮ǰ���׽ڵ�ľ������
	//֮ǰ���׽ڵ㵽���ڵ�ľ���
	return father[x]; 
} 
//·��ѹ��  ֻ����ÿ���ڵ�ĸ��ڵ㣬���������������ṹ
//��һ�β�ѯ��ʱ�򣬰�·�������еĵ�father[i]��ֵΪ���ڵ�
int get1(int x){
	if(father[x] == x){
		return x;
	}
	return father[x] = get(father[x]);
} 
//�ϲ� 
void merge(int x,int y){
	x = get(x);
	y = get(y);
	if(x != y){//����ж��Ƿ���� �� 
		father[y] = x;
	}
} 

//��Ȩ�ϲ�
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
