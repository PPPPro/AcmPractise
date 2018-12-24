#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
using namespace std;
A prime number (or a prime) is a natural number greater than 11 that cannot be formed by multiplying two smaller natural numbers.

Now lets define a number NN as the supreme number if and only if each number made up of an non-empty subsequence of all the numeric digits of NN must be either a prime number or 11.

For example, 1717 is a supreme number because 11, 77, 1717 are all prime numbers or 11, and 1919 is not, because 99 is not a prime number.

Now you are given an integer N\ (2 \leq N \leq 10^{100})N (2≤N≤10 
100
 ), could you find the maximal supreme number that does not exceed NN?

Input

typedef long long int64;

int size;
struct Node
{
    int x, f;
};
int adj[1<<10], to[1<<20], weight[1<<20],nextt[1<<20];
int visited_count[1<<10];
Node heap[1<<20];
int dist[1<<10];
int S, T, K, N, M;

bool flag[1<<10];
int adj1[1<<10], to1[1<<20], weight1[1<<20], next1[1<<20];

inline void adjust_down(int root)
{
    Node x = heap[root];
    int j;
    for (j = root<<1; j <= size; j <<= 1)
    {
        if (j < size && heap[j+1].f < heap[j].f) ++j;
        if (x.f <= heap[j].f) break;
        heap[j>>1] = heap[j];
    }
    heap[j>>1] = x;
}
inline void adjust_up(int root)
{
    Node x = heap[root];
    for (; root>>1; root >>= 1)
    {
        if (heap[root>>1].f <= x.f) break;
        heap[root] = heap[root>>1];
    }
    heap[root] = x;
}
inline Node get_min()
{
    Node result = heap[1];
    heap[1] = heap[size--];
    if (size > 1) adjust_down(1);
    return result;
}
inline void insert(Node x)
{
    heap[++size] = x;
    adjust_up(size);
}

inline int a_star()
{
    Node f, r;
    size = 1;
    heap[1].x = S;
    heap[1].f = dist[S];
    memset(visited_count, 0, sizeof visited_count);
    while (size)
    {
        f = get_min();
        ++visited_count[f.x];
        if (visited_count[T] == K) return f.f;
        if (visited_count[f.x] > K) continue;
        int i;
        for (i = adj[f.x]; i != -1; i = nextt[i])
        {
            int u = to[i];
            if (visited_count[u] >= K) continue;
            int ds = f.f - dist[f.x];
            r.x = u;
            r.f = ds + weight[i] + dist[u];
            insert(r);
        }
    }
    return -1;
}

inline void dijkstra()
{
    memset(flag, 0, sizeof flag);
    for (int i = 1; i <= N; ++i) dist[i] = 0x0fffffff;
    dist[T] = 0;
    for (;;)
    {
        int pos = -1, best = 0x0fffffff;
        for (int j = 1; j <= N; ++j) if (!flag[j] && dist[j] < best)
        {
            pos = j;
            best = dist[j];
        }
        if (pos == -1) break;
        flag[pos] = 1;
        for (int j = adj1[pos]; j != -1; j = next1[j])
        {
            int u = to1[j];
            if (flag[u]) continue;
            int t = best + weight1[j];
            if (t < dist[u])
            {
                dist[u] = t;
            }
        }
    }
}
int main()
{
    while (scanf("%d%d", &N, &M) == 2)
    {
        int t;
        scanf("%d%d%d%d", &S, &T, &K,&t);
        memset(adj, 255, sizeof adj);
        memset(adj1, 255, sizeof adj1);
        for (int i = 0; i < M; ++i)
        {
            int u, v, w;scanf("%d%d%d", &u, &v, &w);
            to[i] = v;
            weight[i] = w;
            nextt[i] = adj[u];
            adj[u] = i;

            to1[i] = u;
            weight1[i] = w;
            next1[i] = adj1[v];
            adj1[v] = i;
        }
        if (S == T) ++K;
        dijkstra();
        if (dist[S] == 0x0fffffff) puts("-1");
        else{
            if(a_star() <= t)
                printf("yareyaredawa\n");
            else
                printf("whitesnake\n");
            printf("%d",a_star());
        }

    }
    return 0;
}
