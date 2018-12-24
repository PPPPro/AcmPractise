const int MAX_N = 10000;
const int MAX_M = 100000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, w, next;
} e[MAX_M];
int p[MAX_N], eid, n;
void mapinit() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int w) {  // �����Ȩ�����
    e[eid].v = v;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void insert2(int u, int v, int w) {  // �����Ȩ˫���
    insert(u, v, w);
    insert(v, u, w);
}

int dist[MAX_N];  // �洢��Դ���·�Ľ��
bool vst[MAX_N];  // ���ÿ�������Ƿ��ڼ��� U ��
bool dijkstra(int s) {
    memset(vst, 0, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_w = inf;  // ��¼ dist ��С�Ķ����ź� dist ֵ
        for (int j = 0; j < n; ++j) {
            if (!vst[j] && dist[j] < min_w) {
                min_w = dist[j];
                v = j;
            }
        }
        if (min_w == inf) {  // û�п��õĶ��㣬�㷨������˵���ж����޷���Դ�㵽��
            return false;
        }
        vst[v] = true;  // ������ v ���뼯�� U ��
        for (int j = p[v]; j != -1; j = e[j].next) {
            // ����� v ���ڵĶ��� x ���� dist[v] + w(v, x) < dist[x] ����� dist[x]����һ�㱻�������ɳڡ�����
            int x = e[j].v;
            if (!vst[x] && dist[v] + e[j].w < dist[x]) {
                dist[x] = dist[v] + e[j].w;
            }
        }
    }
    return true;  // Դ����Ե������ж��㣬�㷨��������
}
