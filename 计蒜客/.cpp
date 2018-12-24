#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
using namespace std;
int res = 0,n,m;
char a[100][100];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int dfs(int x,int y){
    if(x>=0&&x<=m-1&&y>=0&&y<=n-1){
        if(a[x][y] == 'T'){
            res++;
            return 0;
        }
        else if(a[x][y] == '.'|| a[x][y] == 'S'){
            dfs(x-1,y);
            dfs(x+1,y);
            dfs(x,y+1);
            dfs(x,y-1);
        }
    }
    return 0;
}

int main(){
    string s;
    int n;
    cin >> n;
    cin.clear();
    fflush(stdin);
    getline(cin,s);
    	return 0;
}
