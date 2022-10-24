#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 1 << 30
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int t, zc[200], hc[200][200], a[2000][200], m, n, r, c, rb[200], f[200][200], ans = INF;
int ab(int x){
    return (x > 0) ? x : 0 - x;
}
void dp(){
    memset(zc, 0, sizeof(zc));
    memset(hc, 0, sizeof(hc));
    rb[r + 1] = rb[r];
    rep(i, 1, m) rep(j, 1, r)
        zc[i] += ab(a[rb[j]][i] - a[rb[j + 1]][i]);
    rep(i, 1, m - 1) rep(j, i + 1, m) rep(k, 1, r)
        hc[i][j] += ab(a[rb[k]][i] - a[rb[k]][j]);
    memset(f, 0, sizeof(f));
    rep(i, 1, m) f[1][i] = zc[i];
    rep(i, 2, c) rep(j, i, m){
        t = INF;
        rep(k, i - 1, j - 1) t = min(t, f[i - 1][k] + hc[k][j]);
        f[i][j] = t + zc[j];
    }
    rep(i, c, m) ans = min(ans, f[c][i]);
}
void dfs(int k, int p){
    if (k == r){
        dp(); return;
    }
    for (int i = p + 1; i <= n; i++){
        rb[k + 1] = i; dfs(k + 1, i);
    }
}
int main(){
    scanf("%d%d%d%d", &n, &m, &r, &c);
    rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
    dfs(0, 0);
    printf("%d\n", ans);
}
