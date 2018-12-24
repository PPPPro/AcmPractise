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
const int inf = 0x3f3f3f3f;
//区间最大值
struct Node
{
	int L,R;
	int MaxT;
	int mid(){
		return (L+R)/2;
	}
};
Node tree[800000];
int res = 0;
void build(int p,int L,int R){
	tree[p].L = L;
	tree[p].R = R;
	tree[p].MaxT = 0;
	if(L != R){
		build(p*2+1,L,tree[p].mid());
		build(P*2+2,tree[p].mid()+1,R);
	}
}
void insert(int p,int i,int v){
	
}
void query(int p,int L,int R){

}
int main(int argc, char * argv[]) 
{
	int n,q;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		insert(0,i,t);
	}
	for(int i = 1; i <= q; i++){
		char c;
		int a,b;
		scanf("%d %d %d",&c,&a,&b);
		if(c == 'Q'){
			res = 0;
			query(0,a,b);
			cout << res << endl;
		}else{
			insert(0,a,b);
		}
	}
    return 0;
}