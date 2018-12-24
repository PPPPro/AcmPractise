#include<iostream>
#include<algorithm>
using namespace std;
struct Movie{
	int begin,end;
}m[110];

bool cmp(Movie a,Movie b){
	return a.end < b.end;
}

int f(int n){
	int cnt = 0;
	int tmp = m[0].end;
	for(int i = 1; i < n; i++){
		if(m[i].begin >= tmp){
			cnt++;
			tmp = m[i].end;
		}
	}
	return ++cnt;
}

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		for(int i = 0; i < n; i++)
			cin >> m[i].begin >> m[i].end;
	
		sort(m,m+n,cmp);
		cout << f(n) << endl;
	}
	
	return 0;
}