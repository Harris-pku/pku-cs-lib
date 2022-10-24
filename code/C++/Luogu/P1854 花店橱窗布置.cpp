#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[105][105], a[105][105], n, m;
void printt(int i, int j){
    if (!j) return;
    for (int k = 0; k <= i-j; ++k)
        if (dp[i][j] == dp[j+k-1][j-1] + a[j][j+k]){
            printt(j+k-1, j-1); printf("%d ", j+k); return;
        }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i)
        dp[i][i] = dp[i-1][i-1] + a[i][i];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j){
            dp[i][j] = -0x3f3f3f3f;
            for (int k = 0; k <= i-j; ++k)
                dp[i][j] = max(dp[i][j], dp[j+k-1][j-1] + a[j][j+k]);
        }
    printf("%d\n", dp[m][n]);
    printt(m, n);
    return 0;
}
