/*��ͷ��������������ĩ��Լȥ�ٻ�ʦϿ��̤�ࡣ���Ƿ����ٻ�ʦϿ�ȵĵ�ͼ����һ��һ�������ɵģ��еĸ������ǲݴԣ��е��ǿյء��ݴ�ͨ���������� 44 ��������չ�����ݴ��γ�һƬ�ݵأ��κ�һƬ�ݵ��еĸ��Ӷ��ǲݴԣ��������и���֮�䶼��ͨ������������ͨ�������'G'����ݴԣ�'.'����յأ������Ͽ������ 22 Ƭ�ݵء�


1
GG..
2
..GG
����ͬһ���ݵص� 22 ���˿����໥�������յؿ������ݵ�������ˡ����Ƿ�����һ�����Ѳ����ˣ�������Ҫ��ͷȥ�ң�ÿ���˸���һƬ�ݵأ���ͷ����֪������������Ҫ�����ˡ�

�����ʽ
��һ������ nn, mm (1 \le n,m \le 100)(1��n,m��100) ��ʾϿ�ȴ�С

���������� nn ���ַ�����ʾϿ�ȵĵ���

�����ʽ
���������Ҫ������

��������
5 6
.#....
..#...
..#..#
...##.
.#....
�������
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
