#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector> 
const int MAX_N = 110;
using namespace std;
int n;
vector < vector<int> > map(MAX_N);
int main(){
	int x[MAX_N],y[MAX_N];
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 1; i <= n; i++){
		int xx = x[i];
		int yy = y[i];
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			float dis = sqrt((xx-x[j])*(xx-x[j])+(yy-y[j])*(yy-y[j]));
		//	cout << dis << endl;
			printf("%.2f\n",dis);
		}
	}
	
	return 0;
} 
