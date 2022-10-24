#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int v[10005], nex[10005], h[1005];
int q[1000005], vis[1005], head, tail, n, m, x, y, ans, cur;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        v[i] = y; nex[i] = h[x]; h[x] = i;
        v[m + i] = x; nex[m + i] = h[y]; h[y] = m + i;
    }
    
    for (int i = 1; i <= n; ++i){
        if (!vis[i]){
            q[head = 0] = i; tail = 1; vis[i] = 1; ans++;
            while (head < tail){
                cur = q[head++];
                int p = h[cur];
                while (p){
                    if (!vis[v[p]]){
                        vis[v[p]] = 1; q[++tail] = v[p];
                    }
                    p = nex[p];
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}