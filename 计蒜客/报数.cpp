/*有 nn 个小朋友做游戏，他们的编号分别是 1,2,3...n1,2,3...n。他们按照编号从小到大依次顺时针围成一个圆圈，从第一个小朋友开始从 11 报数，依次按照顺时针方向报数(加一)，报 mm 的人会离开队伍，然后下一个小朋友会继续从 11 开始报数，直到只剩一个小朋友为止。

输入格式
第一行输入俩个整数，nn，mm。（1 \leq n,m \leq 10001≤n,m≤1000）

输出格式
输出最后一个小朋友的编号，占一行。

样例输入
10 5
样例输出
3*/
#include <iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,m,tmp,ans = 0;
	queue<int> q;
	cin >> n >> m;
	for(i = 1; i <= n; i++){
        q.push(i);
	}
    while(q.size() > 1){
        for(i = 1; i < m; i++){
            q.push(q.front());
            q.pop();
        }
 //       cout << q.front()<<endl;
        q.pop();
    }
    cout << q.front();
	return 0;
}
