#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[15][20], pa[15][20][15], a[15][20], n, m;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= j; ++k)
                if (dp[i][j] <= dp[i-1][j-k] + a[i][k]){
                    dp[i][j] = dp[i-1][j-k] + a[i][k];
                    for (int h = 1; h < i; ++h)
                        pa[i][j][h] = pa[i-1][j-k][h];
                    pa[i][j][i] = k;
                }
    printf("%d\n", dp[n][m]);
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", i, pa[n][m][i]);
    return 0;
}