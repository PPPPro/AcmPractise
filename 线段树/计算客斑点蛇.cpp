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
#define LOCAL

struct CNode
{
	int L,R;
	int Sum;
	int mid(){
		return (L+R)/2;
	}
};
CNode tree[200010];
int res = 0;
void build(int root,int L,int R){
	tree[root].L = L;
	tree[root].R = R;
	tree[root].Sum = 0;
	if( L != R ){
		build(root*2+1,L,tree[root].mid());
		build(root*2+2,tree[root].mid()+1,R);
	}
}
int cal(int root,int l,int r){
	int len - l - r;
	for(int )
}
void insert(int root,int i,int n){
	if(tree[root].L == tree[root].R){
		tree[root].Sum = n;
		return;
	}
	if(tree[root].mid() >= i){
		insert(root*2+1,i,n);
	}else if(tree[root].mid() < i){
		insert(root*2+2,i,n);
	}

}
void query(int root,int L,int R){
	if(tree[root].L >= L && tree[root].R <= R){
		// cout << "1: " << L << " " << R << endl;
		// cout <<"2 :"<< tree[root].L << " " << tree[root].R << " " << tree[root].Sum << endl;
		 res += tree[root].Sum;
		return; 
	}
	if(R <= tree[root].mid()){
		query(root*2+1,L,R);
	}else if(L > tree[root].mid()){
		query(root*2+2,L,R);
	}else{
		query(root*2+1,L,tree[root].mid());
		query(root*2+2,tree[root].mid()+1,R);
	}
}
int main(int argc, char * argv[])
{
    int n;
    scanf("%d",&n);
    build(0,1,n);
    for(int i = 1; i <= n; i++){
    	int t;
    	cin >> t;
    	insert(0,i,t);
    }
    string s;
    while(cin >> s){
    	int a,b;
    	cin >> a >> b;
    	if(s == "End")break;
    	if(s == "Query"){
    		res = 0;
    		query(0,a,b);
    		cout << res << endl;
    	}else if(s == "Add"){
    		insert(0,a,b);
    	}else{
    		b=b*(-1);
    		insert(0,a,b); 
    	}
    }    return 0;
}