#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#define ll long long

using namespace std;

const int maxn = 10005;
const int maxm = 50005;
const ll INF = 0x7fffffff;
queue<int> q;
struct Edge{
    int v, w, next;
}e[2*maxm];
int en, n, m, C[maxn], inq[maxn], front[maxn];
ll d[maxn], B;
inline void AddEdge(int u, int v, int w){
    e[++en].v = v; e[en].w = w;
    e[en].next = front[u];
    front[u] = en;
}
bool can(int upc){
    memset(inq, 0, sizeof(inq));
    for (int i = 1; i <= n; i++){
        d[i] = INF;
        if (C[i] > upc)
            inq[i] = 1;
    }
    if (C[1] > upc || C[n] > upc)
        return false;
    d[1] = 0; inq[1] = 1; q.push(1);
    while (!q.empty()){
        int u = q.front();
        q.pop(); inq[u] = 0;
        for (int i = front[u]; i >= 0; i = e[i].next){
            int v = e[i].v, w = e[i].w;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                if (!inq[v]){
                    inq[v] = 1; q.push(v);
                }
            }
        }
    }
    return d[n] <= B;
}
int main(){
    memset(front, -1, sizeof(front));
    scanf("%d%d%lld", &n, &m, &B);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    int u, v, w;
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &u, &v, &w);
        AddEdge(u, v, w); AddEdge(v, u, w);
    }
    int tmpc[maxn];
    memcpy(&tmpc, &C, sizeof(C));
    sort(tmpc+1, tmpc+n+1);
    int L = 1, R = n + 1, M;
    while (L < R){
        M = L + (R - L) / 2;
        if (can(tmpc[M]))
            R = M;
        else
            L = M + 1;
    }
    if (L > R || (L == R && !can(tmpc[L])))
        printf("AFK\n");
    else
        printf("%d\n", tmpc[L]);
    return 0;
}
