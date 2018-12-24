#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int Max = 100000001;
int n,k,m;
int p[Max];
int res = 0;
void dfs(int n_m,int cnt,int step){
    if(n_m == 0&&cnt == k){
        res++;
        return;

    }
    else if(n_m<=0 || cnt >= k || step >= n){return;}
    else{
        dfs(n_m-p[step],cnt+1,step+1);
        dfs(n_m,cnt,step+1);
    }
    return;
}
int main(){
	int i,j,tmp,ans = 0;
	cin >> m >> n >>k;
	for(i = 0; i < n; i++){
        cin >> p[i];
	}
	dfs(m,0,0);
	if(res)cout<<"Yes";
	else cout << "No";
	return 0;
}
