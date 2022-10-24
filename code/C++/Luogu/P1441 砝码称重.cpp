#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[2005], vis[25], a[25], n, m, ans;
void dp(){
    memset(f, 0, sizeof(f)); f[0] = 1;
    int cnt = 0, tot = 0;
    for (int i = 1; i <= n; ++i){
        if (vis[i]) continue;
        for (int j = tot; j >= 0; --j)
            if (f[j] && (!f[j+a[i]])){
                f[j+a[i]] = 1; cnt++;
            }
        tot += a[i];
    }
    ans = max(ans, cnt);
}
void dfs(int cur, int num){
    if (num > m) return;
    if (cur == n+1){
        if (num == m) dp(); return;
    }
    dfs(cur+1, num);
    vis[cur] = 1;
    dfs(cur+1, num+1);
    vis[cur] = 0;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}