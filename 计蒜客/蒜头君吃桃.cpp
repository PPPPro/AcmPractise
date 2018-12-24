/*蒜头君买了一堆桃子不知道个数，第一天吃了一半的桃子，还不过瘾，有多吃了一个。以后他每天吃剩下的桃子的一半还多一个，到 nn 天只剩下一个桃子了。蒜头君想知道一开始买了多少桃子。

输入格式
输入一个整数 n(2 \le n \le 60)n(2≤n≤60)，代表第 nn 只剩了一个桃子。

输出格式
输出买的桃子的数量。

样例输入1
2
样例输出1
4
样例输入2
3
样例输出2
10*/
#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int res;
int f(int n){
    if(n == 1)return 1;
    res = (f(n-1)+1) * 2;
    return res;
}
int main(){
	int i,j,n,tmp,ans = 0;
	cin >> n;
	cout<<f(n);
	return 0;
}
