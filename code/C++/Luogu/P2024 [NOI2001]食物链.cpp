#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int fa[300005];
inline int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
inline void unify(int x, int y){
    fa[found(x)] = found(y);
}
int n, m, k, x, y, ans;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n*3; ++i) fa[i] = i;
    while (m--){
        scanf("%d%d%d", &k, &x, &y);
        if (x>n || y>n) ans++;
        else if (k == 1){
            if (found(x+n)==found(y) || found(x)==found(y+n)) ans++;
            else{
                unify(x, y); unify(x+n, y+n); unify(x+n+n, y+n+n);
            }
        }
        else{
            if (found(x)==found(y) || found(x)==found(y+n)) ans++;
            else{
                unify(x+n, y); unify(x+n+n, y+n); unify(x, y+n+n);
            }
        }
    }
    printf("%d", ans);
    return 0;
}