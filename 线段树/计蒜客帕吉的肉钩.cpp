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
struct Node{
	int L,R;
	int sum;
	int Inc;
	Node *pL,*pR;
}tree[200000];
int nCount = 0;

int Mid(Node *root){
	return (root->L + root->R)/2;
}

void build(Node *root,int L,int R){
	root->sum = 1;
	root->Inc = 0;
	root->L = L;
	root->R = R;
	if(L == R)
		return;
	root->pL = tree + (++nCount); 
	root->pR = tree + (++nCount);
	build(root->pL,L,(L+R)/2);
	build(root->pR,(L+R)/2+1,R);
}

void insert(Node *root,int x,int y,int z){
	if(root->L == x && root->R == y){
		root->Inc = z;
		return;
	}
	root->sum = z*(y - x + 1);cout << "insert: "<< root->L << " " << root->R <<" " << root->sum << " " << root->Inc << endl;
	
	if(y <= Mid(root)){
		insert(root->pL,x,y,z);
	}else if(x > Mid(root)){
		insert(root->pR,x,y,z);
	}else{
		insert(root->pL,x,Mid(root),z);
		insert(root->pR,Mid(root)+1,y,z);
	}
}

int query(Node * root,int L,int R){
	cout << "query: " << root->L << " " << root->R <<" " << root->sum << " " << root->Inc << endl;
	
	if(root->L == L && root->R == R){
		if(root->Inc == 0)
			return root->sum;
		else
			return root->Inc * (R - L + 1);
	}
	if(root->Inc != 0){
		root->sum = root->Inc*(R-L+1);
		insert(root->pL,root->L,Mid(root),root->Inc);
		insert(root->pR,Mid(root)+1,root->R,root->Inc);
		root->Inc = 0;
	}
	if(R <= Mid(root))
		return query(root->pL,L,R);
	else if(L > Mid(root))
		return query(root->pR,L,R);
	else{
		return query(root->pL,L,Mid(root))+query(root->pR,Mid(root)+1,R);
	}
}

int main(int argc, char * argv[]) 
{
    int n,q;
    cin >> n >> q;
    build(tree,1,n);
    while(q--){
    	int x,y,z;
    	cout << "T:";
    	cin >> x >> y >> z;
    	insert(tree,x,y,z);
    }
    cout << query(tree,1,n) << endl;
    return 0;
}