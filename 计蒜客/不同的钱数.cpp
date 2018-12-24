#include<iostream>
#include<set>;
using namespace std;
int a[] = {2,2,2,2,3,3,3,5,5}; 
set<int> s;
void dfs(int deep,int res){
	if(deep == 9){
		s.insert(res);
		return;
	}
	dfs(deep+1,res+a[deep]);
	dfs(deep+1,res);
	return;
}
int main(){
	dfs(0,0);
	int cnt = 0;
	for(set<int>::iterator it = s.begin();
	it != s.end(); it++){
		cout << *it << endl;
	}
	cout << s.size();
}
