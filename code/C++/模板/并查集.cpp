#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int fa[1005], n, m;
int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int x, y;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        if (found(x) != found(y)){
            fa[x] = y;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", fa[i]);
    return 0;
}