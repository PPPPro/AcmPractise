#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n;
int A[16];
bool is_prime[100];
bool vis[16];
void dfs(int cur){

    if(cur == n && is_prime[A[0]+A[n-1]]){
        for(int i = 0; i < n; i++){
            cout << A[i] << " ";
        }cout << endl;
        return;
    }
    for(int i = 2; i <= n; i++){
     //   cout << i << " "<< A[cur-1]<< " " << is_prime[i+A[cur-1]] << endl;
        if(!vis[i]&& is_prime[i+A[cur-1]]){
            //printf("cur: %d A: %d\n",cur,i);
            A[cur] = i;
            vis[i] = true;
            dfs(cur+1);
            vis[i] = false;
        }
    }
}
void isp(){
    for (int i = 2; i <= 100; ++i) {
        is_prime[i] = 1;
    }
    for (int i = 2; i * i <= 100; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 100; j +=i) {
                 is_prime[j] = 0;
            }
        }
    }
}
int main(){
    isp();
    while(cin >> n){
        memset(vis,false,sizeof(vis));

            //cout << "A[0] " << i << endl;
            A[0] = 1;
            vis[0] = true;
            dfs(1);
    }
    return 0;
}
