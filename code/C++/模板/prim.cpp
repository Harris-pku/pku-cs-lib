#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

int a[5005][5005], f[5005] = {0, -1}, lowcost[5005];
int n, m, ans, tot, x, y, z, bef = 1;
int main(){
    scanf("%d%d", &n, &m);
    memset(a, -1, sizeof(a));
    memset(lowcost, 1, sizeof(lowcost));
    for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", &x, &y, &z);
        if (a[x][y] == -1) a[x][y] = a[y][x] = z;
        else a[x][y] = a[y][x] = min(a[x][y], z);
    }
    for (int k = 2; k <= n; ++k){
        int mincost = INF, minpo = 0;
        for (int i = 2; i <= n; ++i)
            if (f[i] != -1){
                if (a[bef][i] != -1 && a[bef][i] < lowcost[i])
                    lowcost[i] = a[bef][i];
                if (lowcost[i] < mincost){
                    minpo = i; mincost = lowcost[i];
                }
            }
        ans += mincost; f[bef = minpo] = -1;
    }
    printf("%d", ans);
    return 0;
}