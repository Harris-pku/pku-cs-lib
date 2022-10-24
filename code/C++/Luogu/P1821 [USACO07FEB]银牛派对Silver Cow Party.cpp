#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int uu[100005], vv[100005], dis1[1005], dis2[1005], vis[1005], n, m;
int v[100005], w[100005], nex[100005], h[1005];
int q[1000005], head, tail, cur, x, p, ans;
int main(){
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", &uu[i], &vv[i], &w[i]);
        v[i] = vv[i]; nex[i] = h[uu[i]]; h[uu[i]] = i;
    }
    memset(dis1, 0x3f, sizeof(dis1));
    q[head] = x; tail++; dis1[x] = 0; vis[x] = 1;
    while (head < tail){
        cur = q[head++]; p = h[cur]; vis[cur] = 0;
        while (p){
            if (dis1[cur] + w[p] < dis1[v[p]]){
                dis1[v[p]] = dis1[cur] + w[p];
                if (!vis[v[p]]){
                    q[tail++] = v[p]; vis[v[p]] = 1;
                }
            }
            p = nex[p];
        }
    }
    memset(h, 0, sizeof(h));
    for (int i = 1; i <= m; ++i){
        v[i] = uu[i]; nex[i] = h[vv[i]]; h[vv[i]] = i;
    }
    memset(dis2, 0x3f, sizeof(dis2));
    memset(vis, 0, sizeof(vis));
    head = 0; q[head] = x; tail = 1; dis2[x] = 0; vis[x] = 1;
    while (head < tail){
        cur = q[head++]; p = h[cur]; vis[cur] = 0;
        while (p){
            if (dis2[cur] + w[p] < dis2[v[p]]){
                dis2[v[p]] = dis2[cur] + w[p];
                if (!vis[v[p]]){
                    q[tail++] = v[p]; vis[v[p]] = 1;
                }
            }
            p = nex[p];
        }
    }
    for (int i = 1; i <= n; ++i){
        if (i == x) continue;
        ans = max(ans, dis1[i] + dis2[i]);
    }
    printf("%d", ans);
    return 0;
}
