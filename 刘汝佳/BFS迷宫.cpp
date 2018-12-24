#include <iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ci[8]={-1,0,0,1};
int cj[8]={0,1,-1,0};
char mi [20][20];
int tmp[20][20];
int n,m;
int bfs(int x;int y){
    int i;
    for(i = 0; i < n; i++){

    }
}
int main(){
	int i,j,tmp,ans = 0;
	memset(-1,tmp,sizeof(tmp));
	int s_i,s_j;
	cin >> n >> m;
	for(i = 0; i < n; i++)
        for(j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                s_i = i;
                s_j = j;
            }
        }
    bfs(i,j);

	return 0;
}
