/*�� nn ��С��������Ϸ�����ǵı�ŷֱ��� 1,2,3...n1,2,3...n�����ǰ��ձ�Ŵ�С��������˳ʱ��Χ��һ��ԲȦ���ӵ�һ��С���ѿ�ʼ�� 11 ���������ΰ���˳ʱ�뷽����(��һ)���� mm ���˻��뿪���飬Ȼ����һ��С���ѻ������ 11 ��ʼ������ֱ��ֻʣһ��С����Ϊֹ��

�����ʽ
��һ����������������nn��mm����1 \leq n,m \leq 10001��n,m��1000��

�����ʽ
������һ��С���ѵı�ţ�ռһ�С�

��������
10 5
�������
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
