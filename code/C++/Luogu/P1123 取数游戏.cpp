#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int a[10][10], f[10][10], T, n, m, ans, sum;
void dfs(int x, int y){
    if (x == n+1){
        ans = max(ans, sum); return;
    }
    int xx = x, yy = y+1;
    if (yy == m+1){
        xx++; yy = 1;
    }
    if (!f[x-1][y] && !f[x][y-1] && !f[x-1][y-1] && !f[x-1][y+1]){
        f[x][y] = 1; sum += a[x][y];
        dfs(xx, yy);
        f[x][y] = 0; sum -= a[x][y];
    }
    dfs(xx, yy);
} 
int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m); ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}