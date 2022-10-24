#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fa[1005], n, m, x, y, ans;
int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int main(){
    while (scanf("%d%d", &n, &m)==2 && n){
        ans = n-1;
        for (int i = 1; i <= n; ++i) fa[i] = i;
        for (int i = 1; i <= m; ++i){
            scanf("%d%d", &x, &y);
            int fx = found(x), fy = found(y);
            if (fx != fy){
                fa[fx] = fy; ans--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}