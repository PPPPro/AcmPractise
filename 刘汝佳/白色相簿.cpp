#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int Max = 3000000;
int n,m;
int num[100000],r1[Max],r2[Max];
set<int> rs;
int main(){
	int i,j;
	cin >> n >> m;
	for(i = 0; i < m; i++){
		cin >> r1[i] >> r2[i];
	}
	for(i = 0; i < m; i++){
		int a,b;
		a = r1[i];
		b = r2[i];
		for(j = 0; j < m; j++){
			if(i == j)continue;
			if((r1[j] == a && r2[j] == b) || (r1[j] == b && r2[j] == a))continue;
			if(r1[j] == a){
				if(rs.count(r2[j])){
					cout << "1";
					return 0;
				}
				rs.insert(r2[j]);
			}
			else if(r2[j] == b){
				if(rs.count(r1[j])){
					cout << "1";
					return 0;
				}
				rs.insert(r1[j]);
			}
			else if(r1[j] == b){
				if(rs.count(r2[j])){
					cout << "1";
					return 0;
				}
				rs.insert(r2[j]);
			}
			else if(r2[j] == a){
				if(rs.count(r1[j])){
					cout << "1";
					return 0;
				}
				rs.insert(r1[j]);
			}
		}
		rs.clear();
	}
	cout <<"0";
	return 0;
} 
