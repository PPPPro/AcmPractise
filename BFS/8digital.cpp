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
int qcnt = 0;
int st[3][3];
int res[3][3];
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};
set<int> s;
struct Point {
	int p_st[3][3];
	int step;
};
bool cmp(int (&A)[3][3],int (&B)[3][3]){
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(A[i][j] != B[i][j])return false;
	return true;
}
bool find(int A[3][3]){
	int res = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			res = res*10 + A[i][j];
	if(s.count(res))return true;
	s.insert(res);
	return false;
}
int bfs(){

	queue<Point> q;
	Point  tt;
	memcpy(tt.p_st,st,sizeof(st));
	tt.step = 0;
	q.push(tt);
	while(!q.empty()){
		//cout << "qcnt: " << qcnt++ << endl;
		Point t = q.front();
		q.pop();
		if(memcmp(t.p_st,res,sizeof(res))==0)
			return t.step;
		int zero_x,zero_y;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				if(t.p_st[i][j] == 0){
					zero_x = i;
					zero_y = j;
				}
			
		for(int i = 0; i < 4; i++){
			int tx,ty;
			tx = zero_x+xx[i];
			ty = zero_y+yy[i];
			if(tx >= 0 && ty >= 0 && tx < 3 && ty < 3){

				//cout << "forif";
				int chan;
				Point pt;
				memcpy(pt.p_st,t.p_st,sizeof(t.p_st));
				pt.step = t.step+1;
				chan = pt.p_st[tx][ty];
				pt.p_st[tx][ty] = pt.p_st[zero_x][zero_y];
				pt.p_st[zero_x][zero_y] = chan;
				if(!find(pt.p_st)){
				//	cout << " push ";
					q.push(pt);
				}
			}
		}
		//cout << endl;
	}return -1;

}
int main(int argc, char * argv[])
{
	for(int i = 0 ; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> st[i][j];
		cout << " st finish" << endl;
	for(int i = 0 ; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> res[i][j];
	cout << bfs();

    return 0;
}