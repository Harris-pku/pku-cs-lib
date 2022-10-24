#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fa[10005], v[10005], w[10005], n, m, k, x, y;
int f[10005], vv[10005], ww[10005], tot;
int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d", &v[i], &w[i]); fa[i] = i;
	}
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        int fx = found(x), fy = found(y);
        if (fx != fy){
            fa[fy] = fx; v[fx] += v[fy]; w[fx] += w[fy];
            v[fy] = w[fy] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (v[i] && v[i]<=k){
            vv[++tot] = v[i]; ww[tot] = w[i];
        }
    for (int i = 1; i <= tot; ++i)
        for (int j = k; j >= vv[i]; --j)
            f[j] = max(f[j], f[j-vv[i]]+ww[i]);
    printf("%d", f[k]);
    return 0;
}
