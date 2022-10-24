#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 300005;
int p[maxn][20], son[maxn], son2[maxn], son3[maxn], f[maxn];
int s[maxn], s2[maxn], pr[maxn], T, n, cnt; long long ans;
int v[maxn*2], nex[maxn*2], h[maxn];
void dfs(int x, int fa){
    s[x] = 1; pr[x] = fa;
    for (int i = h[x]; i; i = nex[i]){
        int y = v[i];
        if (y == fa) continue;
        dfs(y, x); s[x] += s[y];
        if (s[y] > s[son[x]]){
            son2[x] = son[x]; son[x] = y;
        }
        else if (s[y] > s[son2[x]])
            son2[x] = y;
    }
    p[x][0] = son[x];
    for (int i = 1; i <= 17; ++i)
        p[x][i] = p[p[x][i-1]][i-1];
}
int judge(int x, int sum){
    return x * (max(s2[son3[x]], sum-s2[x]) <= sum/2);
}
void dfs2(int x, int fa){
    for (int i = h[x]; i; i = nex[i]){
        int y = v[i];
        if (y == fa) continue;
        s2[x] = s[1] - s[y]; f[y] = f[x] = 0;
        if (son[x] == y)
            son3[x] = son2[x];
        else son3[x] = son[x];
        if (s2[fa] > s2[son3[x]])
            son3[x] = fa;
        p[x][0] = son3[x];
        for (int j = 1; j <= 17; ++j)
            p[x][j] = p[p[x][j-1]][j-1];
        int t = x;
        for (int j = 17; j >= 0; --j)
            if (s2[x]-s2[p[t][j]] <= s2[x]/2)
                t = p[t][j];
        ans += judge(son3[t], s2[x]) + judge(t, s2[x]) + judge(f[t], s2[x]);
        t = y;
        for (int j = 17; j >= 0; --j)
            if (s2[y]-s2[p[t][j]] <= s2[y]/2)
                t = p[t][j];
        ans += judge(son3[t], s2[y]) + judge(t, s2[y]) + judge(f[t], s2[y]);
        f[x] = y; dfs2(y, x);
    }
    son3[x] = p[x][0] = son[x]; f[x] = pr[x];
    for (int i = 1; i <= 17; ++i)
        p[x][i] = p[p[x][i-1]][i-1];
    s2[x] = s[x];
}
int main(){
    scanf("%d", &T);
    while (T--){
        memset(h, 0, sizeof(h));
        memset(f, 0, sizeof(f));
        memset(pr, 0, sizeof(pr));
        memset(son, 0, sizeof(son));
        cnt = ans = 0;
        scanf("%d", &n);
        for (int i = 1; i < n; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            v[++cnt] = y; nex[cnt] = h[x]; h[x] = cnt;
            v[++cnt] = x; nex[cnt] = h[y]; h[y] = cnt;
        }
        dfs(1, 0);
        memcpy(f, pr, sizeof(pr));
        memcpy(s2, s, sizeof(s2));
        memcpy(son3, son, sizeof(son3));
        dfs2(1, 0);
        cout << ans << endl;
    }
    return 0;
}