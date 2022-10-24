#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[60][60][65], dis[60][60], n, m, x, y;
int main(){
    scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        dis[x][y] = 1; a[x][y][0] = 1;
    }
    for (int t = 1; t <= 64; ++t)
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (a[i][k][t-1] && a[k][j][t-1]){
                        a[i][j][t] = dis[i][j] = 1;
                    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    printf("%d", dis[1][n]);
    return 0;
}
