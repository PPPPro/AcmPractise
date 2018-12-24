#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n,M,ans=0;
int k[21],p[21],x[21];
int f(int x,int y){
    int tmp = 1;
    for(int i = 0; i < y; i++){
        tmp *= x;
    }
    return tmp;
}
void dfs(int cnt,int res){
    if(res == 0 && cnt == n+1){
        ans++;
        return;
    }
    else if(
             cnt >= n+1)return;
    else{
        for(int i = 1; i <= M; i++){
            int tmp;
            tmp = f(i,p[cnt])*k[cnt];
            res += tmp;
            dfs(cnt+1,res);
            res -= tmp;
        }
    }
    return;
}
int main(){
	int i,j,tmp;
	cin >> n >> M;
	for( i = 1; i <= n; i++){
        cin >> k[i] >> p[i];
	}
	ans = 0;
	dfs(1,0);
	cout << ans;
	return 0;
}
