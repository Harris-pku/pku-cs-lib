#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct node{
    int v, w, nex;
}e[500010];
queue<int> q;
int vis[10010], dis[10010], h[10010];
int n, m, tot, s, end, x, y, z;
int add(int x, int y, int z){
    e[++tot].v = y; e[tot].w = z;
    e[tot].nex = h[x]; h[x] = tot;
}
int main(){
	memset(dis, 127, sizeof dis);
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", &x, &y, &z);
        add(x,y,z);
    }
    vis[s] = 1; dis[s] = 0;
    q.push(s);
    while (!q.empty()){
        int cur = q.front(); q.pop();
        int t = h[cur]; vis[cur] = 0;
        while (t != 0){
            if (dis[e[t].v] > dis[cur] + e[t].w){
                dis[e[t].v] = dis[cur] + e[t].w;
                if (!vis[e[t].v]){
                    vis[e[t].v] = 1;
                    q.push(e[t].v);
                }
            }
            t = e[t].nex;
        }
    }
    for (int i = 1; i <= n; ++i){
        if (dis[i] == 2139062143)
            dis[i] = 2147483647;
        printf("%d ", dis[i]);
    }
    return 0;
}