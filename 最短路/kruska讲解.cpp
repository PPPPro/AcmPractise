#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;  // ��󶥵���
const int MAX_M = 100000;  // ������

struct edge {
    int u, v, w;
}e[MAX_M];


int fa[MAX_N], n, m;  // fa �����¼�˲��鼯�н��ĸ���
//  father���� 


bool cmp(edge a,edge b) {
    return a.w < b.w;
}


////////////////// ���鼯��ش���////////////////////////////////////////////////
int ancestor(int x) {  // �ڲ��鼯ɭ�����ҵ� x �����ȣ�Ҳ��������ͨ��ı�ʶ
    if(fa[x] == x) return fa[x];
    else return fa[x] = ancestor(fa[x]);
}

int same(int x, int y) {  // �ж��������Ƿ���һ����ͨ�飨���ϣ���
    return ancestor(x) == ancestor(y);
}

void merge(int x, int y) {  // �ϲ�������ͨ�飨���ϣ�
    int fax = ancestor(x), fay = ancestor(y);
    fa[fax] = fay;
}
/////////////////////////////////////////////////////////////////////////////////////


int main() {
    scanf("%d%d", &n, &m);  // n Ϊ������m Ϊ����
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);  // �ñ߼������űߣ���������͵���
    }
    sort(e + 1, e + m + 1, cmp);  // �Ա߰���Ȩ������������
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    int rst = n, ans = 0;  // rst ��ʾ��ʣ���ٸ����ϣ�ans ������С�������ϵ��ܱ�Ȩ
    for (int i = 1; i <= m && rst > 1; i++) {
        int x = e[i].u, y = e[i].v;
        if (same(x, y)) {
            continue;  // same �����ǲ�ѯ�������Ƿ���ͬһ������
        } else {
            merge(x, y);  // merge ����������������ϲ���ͬһ������
            rst--;  // ÿ�ν�������ͬ�����еĵ�ϲ�������ʹ rst ֵ�� 1
            ans += e[i].w;  // ����������С�������еıߣ����𰸼��ϱ�Ȩ
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
