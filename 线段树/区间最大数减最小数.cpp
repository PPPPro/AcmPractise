
// 给定Q (1 ≤ Q ≤ 200,000)个数A1,A2 … AQ,，
// 多次求任一区间Ai – Aj中最大数和最小数的
// 差。
//Poj3264  Balanced Lineup
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int INF = 0xffffff0;
int Value;
struct CNode{
	int L,R;
	int value;
	int Mid(){
		return (L+R)/2;
	}
};
CNode tree[800010];
void build_tree(int root,int L,int R){
	tree[root].L = L;
	tree[root].R = R;
	tree[root].value = 0;
	if(L != R){
		build_tree(root*2+1,L,(L+R)/2);
		build_tree(root*2+2,(L+R)/2+1,R);
	}
}
void insert(int root, int i, int v){
	if(tree[root].L == tree[root].R){
		tree[root].value = v;
		return;
	}
	if(i <= tree[root].Mid())
		insert(root*2+1,i,v);
	else
		insert(root*2+2,i,v);

	tree[root].value = tree[root*2+1].value+tree[root*2+2].value;
}
void query(int root,int L,int R){
	if(tree[root].L == L && tree[root].R == R){
		Value += tree[root].value;
		return;
	}
	if(tree[root].Mid() < L) query(root*2+2,L,R);
	else if(tree[root].Mid() >= R) query(root*2+1,L,R);
	else{
		query(root*2+1,L,tree[root].Mid());
		query(root*2+2,tree[root].Mid()+1,R);
	}
}
int main(int argc, char * argv[]) 
{
    int n,q,h;
    scanf("%d %d",&n,&q);
    build_tree(0,1,n);
    for(int i = 1; i <= n; i++){
    	scanf("%d",&h);
    	insert(0,i,h);
    }
    for(int i = 0; i < q; i++){
    	int c;
    	int s,e;
    	scanf("%d %d %d",&c,&s,&e);
    	if(c == 1){
    		insert(0,s,e);
    	}else{
    		Value = 0;
			query(0,s,e);
			cout << Value << endl;
    	}
    	
    }
    return 0;
}