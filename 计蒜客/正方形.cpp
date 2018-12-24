#include<iostream>
#include<vector> 
using namespace std;
int n,sum,all;
bool ok = 0;
int a[21];
void dfs(int l1,int l2,int l3,int l4,int cnt){
	if(ok || l1 > sum || l2 > sum || l3 > sum || l4 > sum || cnt > n-1 )return;
	else if(l1 == sum && l2 == sum && l3 == sum && all-l1-l2-l3==sum){
		ok = 1;
		return;
	}
	else{
		dfs(l1+a[cnt],l2,l3,l4,cnt+1);
		dfs(l1,l2+a[cnt],l3,l4,cnt+1);
		dfs(l1,l2,l3+a[cnt],l4,cnt+1);
		//dfs(l1,l2,l3,l4+a[cnt],cnt+1);
	}
	return;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		sum += a[i];
	}
	all = sum;
	if(sum%4 != 0){
		cout << "No";
		return 0;
	}
	else{
		
		sum/=4;
		dfs(0,0,0,0,0);
	}
	if(ok)cout<<"Yes";
	else cout<<"No";
	return 0; 
} 
