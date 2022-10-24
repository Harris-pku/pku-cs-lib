#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

struct edge{
    int u, v, w;
    bool operator < (const edge & x) const{
        return w < x.w;
    }
}e[10005];
int fa[2005], n, m, tot;
int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    sort(e+1, e+m+1);
    for (int i = 1; i <= m; i++){
        int fx = found(e[i].u);
        int fy = found(e[i].v);
        if (fx != fy){
            fa[fx] = fy;
            if (++tot == n-1){
                printf("%d", e[i].w); return 0;
            }
        }
    }
    return 0;
}