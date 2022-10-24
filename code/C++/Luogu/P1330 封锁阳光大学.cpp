#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int v[200005], nex[200005], h[10005], vis[10005];
int col[10005], n, m, x, y, s[2], ans;
int dfs(int cur, int color){
    if (vis[cur]){
        if (col[cur] == color) return 1;
        return 0;
    }
    vis[cur] = 1; s[col[cur]=color]++;
    int flag = 1;
    for (int i = h[cur]; i && flag; i = nex[i]){
        flag &= dfs(v[i], color^1);
    }
    return flag;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        v[i] = y; nex[i] = h[x]; h[x] = i;
        v[m+i] = x; nex[m+i] = h[y]; h[y] = m+i;
    }
    for (int i = 1; i <= n; ++i){
        if (vis[i]) continue;
        s[0] = s[1] = 0;
        if (!dfs(i, 0)){
            printf("Impossible"); return 0;
        }
        ans += min(s[0], s[1]);
    }
    printf("%d", ans);
    return 0;
}