#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int v[10005], nex[10005], h[1005], ru[1005];
int q[1000005], vis[1005], head, tail, n, m, x, y, ans, cur;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        v[i] = y; nex[i] = h[x]; h[x] = i;
        ru[y]++;
    }
    for (int i = 1; i <= n; ++i)
        if (!ru[i]) q[tail++] = i;
    while (head < tail){
        cur = q[head++]; printf("%d ", cur);
        int p = h[cur];
        while (p){
            if (--ru[v[p]] == 0) q[tail++] = v[p];
            p = nex[p];
        }
    }
    printf("%d", ans);
    return 0;
}