#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fa[10005], sum[10005], n, m, p, q, ans;
inline int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int x, y;
int main(){
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 1; i <= n; ++i){
        fa[i] = i; sum[i] = 1;
    }
    for (int i = 1; i <= p; ++i){
        scanf("%d%d", &x, &y);
        int fx = found(x), fy = found(y);
        if (fx == fy) continue;
        fa[fx] = fy; sum[fy] += sum[fx];
    }
    ans = sum[found(1)];
    for (int i = 1; i <= m; ++i){
        fa[i] = i; sum[i] = 1;
    }
    for (int i = 1; i <= q; ++i){
        scanf("%d%d", &x, &y);
        x = -x; y = -y;
        int fx = found(x), fy = found(y);
        if (fx == fy) continue;
        fa[fx] = fy; sum[fy] += sum[fx];
    }
    printf("%d", min(ans, sum[found(1)]));
    return 0;
}