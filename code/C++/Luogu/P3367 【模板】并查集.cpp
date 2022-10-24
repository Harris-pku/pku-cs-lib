#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int fa[10005], n, m, p, k;
int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int x, y, fx, fy;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &k, &x, &y);
        fx = found(x); fy = found(y);
        if (k-1)
            if (fx == fy) printf("Y\n");
            else printf("N\n");
        else
            if (fx != fy) fa[fx] = fy;
    }
    return 0;
}
