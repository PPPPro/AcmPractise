/*��ͷ������һ�����Ӳ�֪����������һ�����һ������ӣ�������񫣬�ж����һ�����Ժ���ÿ���ʣ�µ����ӵ�һ�뻹��һ������ nn ��ֻʣ��һ�������ˡ���ͷ����֪��һ��ʼ���˶������ӡ�

�����ʽ
����һ������ n(2 \le n \le 60)n(2��n��60)������� nn ֻʣ��һ�����ӡ�

�����ʽ
���������ӵ�������

��������1
2
�������1
4
��������2
3
�������2
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
