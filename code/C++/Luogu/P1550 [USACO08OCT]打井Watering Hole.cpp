#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

int a[305][305], f[305] = {0, -1}, dis[305];
int n, m, ans, tot, x, y, z, bef = 1;
int main(){
    scanf("%d", &n);
    memset(a, -1, sizeof(a));
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; ++i){
        scanf("%d", &x); a[n+1][i] = a[i][n+1] = x;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            scanf("%d", &a[i][j]); a[j][i] = a[i][j];
        }
    for (int k = 2; k <= n+1; ++k){
        int minm = INF, minn = 0;
        for (int i = 2; i <= n+1; ++i)
            if (f[i] != -1){
                if (a[bef][i] != -1 && a[bef][i] < dis[i])
                    dis[i] = a[bef][i];
                if (dis[i] < minm){
                    minn = i; minm = dis[i];
                }
            }
        ans += minm; f[bef = minn] = -1;
    }
    printf("%d", ans);
    return 0;
}
