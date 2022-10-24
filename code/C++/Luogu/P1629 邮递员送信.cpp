#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int uu[100005], vv[100005], dis[1005], vis[1005], n, m;
int v[100005], w[100005], nex[100005], h[1005];
int q[1000005], head, tail, cur, p, ans;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &uu[i], &vv[i], &w[i]);
        v[i] = vv[i]; nex[i] = h[uu[i]]; h[uu[i]] = i;
    }
    memset(dis, 0x3f, sizeof(dis));
    q[head] = 1; tail++; dis[1] = 0; vis[1] = 1;
    while (head < tail){
        cur = q[head++]; p = h[cur]; vis[cur] = 0;
        while (p){
            if (dis[cur] + w[p] < dis[v[p]]){
                dis[v[p]] = dis[cur] + w[p];
                if (!vis[v[p]]){
                    q[tail++] = v[p]; vis[v[p]] = 1;
                }
            }
            p = nex[p];
        }
    }
    for (int i = 1; i <= n; ++i)
        ans += dis[i];
    
    memset(h, 0, sizeof(h));
    for (int i = 1; i <= m; i++){
        v[i] = uu[i]; nex[i] = h[vv[i]]; h[vv[i]] = i;
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    head = 0; q[head] = 1; tail = 1; dis[1] = 0; vis[1] = 1;
    while (head < tail){
        cur = q[head++]; p = h[cur]; vis[cur] = 0;
        while (p){
            if (dis[cur] + w[p] < dis[v[p]]){
                dis[v[p]] = dis[cur] + w[p];
                if (!vis[v[p]]){
                    q[tail++] = v[p]; vis[v[p]] = 1;
                }
            }
            p = nex[p];
        }
    }
    for (int i = 1; i <= n; i++)
        ans += dis[i];
    
    printf("%d", ans);
    return 0;
}