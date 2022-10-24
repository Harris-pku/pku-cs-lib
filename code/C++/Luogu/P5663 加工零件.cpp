#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int l[100005], r[100005], is_cog;
int v[200005], nex[200005], h[100005], n, m, k, x, y, p;
int dis[100005], flag[100005], q[1000005], head, tail;
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        if (x==1 || y==1) is_cog = 1;
        v[i] = y; nex[i] = h[x]; h[x] = i;
        v[m+i] = x; nex[m+i] = h[y]; h[y] = m+i;
    }
    memset(l, 0x3f, sizeof(l));
    memset(r, 0x3f, sizeof(r));
    r[1] = 0; q[head] = tail = 1;
    while (head < tail){
        x = q[head++]; p = h[x];
        while (p){
            int xx = l[v[p]], yy = r[v[p]];
            l[v[p]] = min(l[v[p]], r[x]+1);
            r[v[p]] = min(r[v[p]], l[x]+1);
            if (l[v[p]]!=xx || r[v[p]]!=yy)
                q[tail++] = v[p];
            p = nex[p];
        }
    }
    for (int i = 1; i <= k; ++i){
        scanf("%d%d", &x, &y);
        if (!is_cog) printf("No\n");
        else if ((y&1 && l[x]<=y) || (!(y&1) && r[x]<=y))
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}