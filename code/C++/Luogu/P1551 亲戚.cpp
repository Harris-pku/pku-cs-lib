#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int fa[5005], n, m, p;
int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int x, y, fx, fy;
int main(){
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        fx = found(x); fy = found(y);
        if (fx != fy){
            fa[fx] = fy;
        }
    }
    for (int i = 1; i <= p; ++i){
        scanf("%d%d", &x, &y);
        fx = found(x); fy = found(y);
        if (fx == fy) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
