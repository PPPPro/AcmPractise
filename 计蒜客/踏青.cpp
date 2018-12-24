/*蒜头君和他的朋友周末相约去召唤师峡谷踏青。他们发现召唤师峡谷的地图是由一块一块格子组成的，有的格子上是草丛，有的是空地。草丛通过上下左右 44 个方向扩展其他草丛形成一片草地，任何一片草地中的格子都是草丛，并且所有格子之间都能通过上下左右连通。如果用'G'代表草丛，'.'代表空地，下面的峡谷中有 22 片草地。


1
GG..
2
..GG
处在同一个草地的 22 个人可以相互看到，空地看不到草地里面的人。他们发现有一个朋友不见了，现在需要分头去找，每个人负责一片草地，蒜头君想知道他们至少需要多少人。

输入格式
第一行输入 nn, mm (1 \le n,m \le 100)(1≤n,m≤100) 表示峡谷大小

接下来输入 nn 行字符串表示峡谷的地形

输入格式
输出至少需要多少人

样例输入
5 6
.#....
..#...
..#..#
...##.
.#....
样例输出
5*/
#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cnt = 0,n,m;
char a[100][100];
int b[100][100];
int t1[5] = {1,0,0,-1};
int t2[5] = {0,1,-1,0};
void dfs(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]=='#'&&b[x][y]==0){

            for(int i = 0; i < 4; i++){
                b[x][y] = 1;
                dfs(x+t1[i],y+t2[i]);
            }

    }
    return;
}
int main(){
	int i,j,tmp,ans = 0;
	cin >> n >> m;

	for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            b[i][j] = 0;
        }
	}
	for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> a[i][j];
        }
	}
	for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
         if(a[i][j] == '#' && b[i][j] == 0){
                dfs(i,j);
               cnt++;
            }
        }
	}
	cout << cnt;
	return 0;
}
