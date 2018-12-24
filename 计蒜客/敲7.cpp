/*有一种酒桌游戏叫做“敲7”，规则是从一个人开始，说出任意数字，其他人会顺序往后报，如果一个数字包含 77，或者是 77 的倍数，那么需要敲打杯子或盘子，不能说出。

现在 nn 个人围坐在一个圆桌周围，他们编号从 11 到 nn 顺时针排列。从某一人开始报出一个数字，其他人会按照顺时针方向顺序往后报(加一)，如果某个人的数字包含 77，或者是 77 的倍数，那么他将退出游戏，下一个人继续接着报，直到剩一个人为止。

输入格式
第一行输入三个整数，nn，mm，tt。nn 代表总人数，mm 代表从第 mm 个人开始报数，他报出的数字是 tt。（1 \leq m \leq n \leq 10001≤m≤n≤1000，1 \leq t \leq 1001≤t≤100）接下来的 nn 行，每一行输入一个字符串，代表这 nn 个人的名字，字符串的长度不超过 2020。

输出格式
输出剩下的那个人的名字，占一行。

样例输入
5 3 20
donglali
nanlali
xilali
beilali
chuanpu
样例输出
chuanpu*/
#include <iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int f(int i){
    while(i > 0){
        int tmp = i%10;
        i /= 10;
        if(tmp == 7)return 1;
    }
    return 0;
}

int main(){

	int i,j,n,m,t,tmp,ans = 0;
	queue<string> q;
	cin >> n >> m >> t;
	string s[n];
	for(i = 0; i < n; i++){
        cin >> s[i];
	}
	for(i = m; i <= n; i++){
        q.push(s[i-1]);
	}
	for(i = 0; i < m-1; i++){
        q.push(s[i]);
	}
	for(i = t; q.size() > 1; i++){
        if(f(i) || i%7==0){
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
	}
	cout<<q.front();

	return 0;
}
