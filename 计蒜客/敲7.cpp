/*��һ�־�����Ϸ��������7���������Ǵ�һ���˿�ʼ��˵���������֣������˻�˳�����󱨣����һ�����ְ��� 77�������� 77 �ı�������ô��Ҫ�ô��ӻ����ӣ�����˵����

���� nn ����Χ����һ��Բ����Χ�����Ǳ�Ŵ� 11 �� nn ˳ʱ�����С���ĳһ�˿�ʼ����һ�����֣������˻ᰴ��˳ʱ�뷽��˳������(��һ)�����ĳ���˵����ְ��� 77�������� 77 �ı�������ô�����˳���Ϸ����һ���˼������ű���ֱ��ʣһ����Ϊֹ��

�����ʽ
��һ����������������nn��mm��tt��nn ������������mm ����ӵ� mm ���˿�ʼ�������������������� tt����1 \leq m \leq n \leq 10001��m��n��1000��1 \leq t \leq 1001��t��100���������� nn �У�ÿһ������һ���ַ����������� nn ���˵����֣��ַ����ĳ��Ȳ����� 2020��

�����ʽ
���ʣ�µ��Ǹ��˵����֣�ռһ�С�

��������
5 3 20
donglali
nanlali
xilali
beilali
chuanpu
�������
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
