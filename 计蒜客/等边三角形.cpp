#include<iostream>
#include<iostream>
using namespace std;
int n,ok = 0,total = 0;
int a[21];
void dfs(int cnt,int l1,int l2,int l3){
	if( cnt >= n || l1 > total ||  l2> total || l3 > total)return;
	else if( l1== total && l3 == total && l2 == total && cnt==n){
		ok = 1;
		return;
	}//(f[0] >=total||f[1]>=total||f[2]>=total)&&cnt>=cnt/2)
	
	else{
		dfs(cnt+1,l1+a[cnt],l2,l3);
		dfs(cnt+1,l1,l2+a[cnt],l3);
		dfs(cnt+1,l1,l2,l3+a[cnt]);
	}
	return;
}
int main(){
	int f[3] ;
	for(int i = 0; i < 3; i++){
		f[i] = 0;
	} 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		total+=a[i];
	}
	total /= 3;
	dfs(0,0,0,0);
			if(ok)cout<<"yes";
			else cout << "no"; 
	return 0;
}
