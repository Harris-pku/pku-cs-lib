#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct edge{
    int u, v, w;
    bool operator < (const edge & x) const{
        return w > x.w;
    }
}a[100005];
int fa[100005];
int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
inline void unify(int x, int y){
    fa[found(x)] = found(y);
}
int n, m, k, x, y, ans;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n*2; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
    sort(a+1, a+m+1);
    for (int i = 1; i <= m+1; ++i){
        if (found(a[i].u)==found(a[i].v) || found(a[i].u+n)==found(a[i].v+n)){
            printf("%d", a[i].w); break;
        }
        else{
            unify(a[i].u, a[i].v+n); unify(a[i].u+n, a[i].v);
        }
    }
    return 0;
}