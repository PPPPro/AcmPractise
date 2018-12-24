#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int b[100][100];
int n,m,x_s,y_s,cnt = 0;
char a[100][100];
int t1[5] = {1,0,-1,0};
int t2[5] = {0,1,0,-1};
void dfs(int x,int y){
        int i;
        if(a[x][y] == 'T'){
        cout << "yes"<<endl;
        cnt++;
        return;
        }
        else if(x>=0&&x<n&&y>=0&&y<m&&a[x][y] != '#' && b[x][y] == 0){
                cout <<"2"<<endl;
            for(i = 0;i < 4;i++){
                cout << "1"<<endl;
                b[x][y] = 1;
                dfs(x+t1[i],y+t2[i]);
                b[x][y] = 0;
            }
        }
    return;
}
int main(){
	int i,j,tmp,ans = 0;
	cin >> n >> m;
	for(i = 0; i < n; i++){
        for(j = 0; j < m; j++)
            b[i][j] = 0;
	}
	for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                x_s = i;
                y_s = j;
            }
        }
	}
	cout <<x_s<<" "<<y_s<<endl;
	dfs(x_s,y_s);

    cout << cnt;
	return 0;
}
