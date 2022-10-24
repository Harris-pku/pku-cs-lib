#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100005;
const int maxm = 200005;
typedef pair<int, int> Pair;
int dis[maxn], h[maxn]; int tot, start, n, m, x, y, z;
int v[maxm], w[maxm], nex[maxm]; bool flag[maxn];
int main(){
	scanf("%d%d%d", &n, &m, &start);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", &x, &y, &z);
        v[i] = y; w[i] = z;
        nex[i] = h[x]; h[x] = i;
    }
    memset(dis, 0x3f, sizeof dis);
    dis[start] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair> >q;
    q.push(make_pair(dis[start], start));
    while (!q.empty()){
        Pair cur = q.top(); q.pop();
        if (flag[cur.second]) continue;
        flag[cur.second] = 1;
        for (int i = h[cur.second]; i; i = nex[i])
            if (dis[cur.second] + w[i] < dis[v[i]]){
                dis[v[i]] = dis[cur.second] + w[i];
                if (!flag[v[i]]) q.push(make_pair(dis[v[i]], v[i]));
            }
    }
    for (int i = 1; i <= n; ++i){
        printf("%d ", dis[i]);
    }
    return 0;
}