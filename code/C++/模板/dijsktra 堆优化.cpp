#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 500010;
typedef pair<int, int>Pair;
struct node{
    int u, w, v, next;
}e[500010];
int dis[maxn], h[maxn]; int tot, start, n, m, x, y, z;
bool flag[maxn];
void add(int x,int y,int z){
    e[++tot].u = x; e[tot].v = y;
    e[tot].w = z; e[tot].next = h[x]; h[x] = tot;
}
int dijsktra(int start){
	memset(dis, 127, sizeof dis);
    memset(flag, 0, sizeof flag);
    dis[start] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair> >q;
    q.push(make_pair(dis[start], start));
    while (!q.empty()){
        Pair cur = q.top(); q.pop();
        if (flag[cur.second]) continue;
        flag[cur.second] = 1;
        for (int i = h[cur.second]; i; i = e[i].next)
            if (dis[cur.second] + e[i].w < dis[e[i].v]){
                dis[e[i].v] = dis[cur.second] + e[i].w;
                if (!flag[e[i].v]) q.push(make_pair(dis[e[i].v], e[i].v));
            }
    }
    for (int i = 1; i <= n; ++i){
        if (dis[i] == 2139062143)
        dis[i] = 2147483647;
     printf("%d ", dis[i]);
    }
}
int main(){
	scanf("%d%d%d", &n, &m, &start);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    dijsktra(start);
    return 0;
}
