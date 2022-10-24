#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long up[1005][1005], down[1005][1005];
long long dp[1005][1005];
int a[1005][1005], n, m;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++){
        dp[i][1] = dp[i-1][1] + a[i][1];
    }
    for (int j = 2; j <= m; j++){
        up[1][j] = dp[1][j-1] + a[1][j];
        for (int i = 2; i <= n; i++){
            up[i][j] = max(up[i-1][j], dp[i][j-1]) + a[i][j];
        }
        down[n][j] = dp[n][j-1] + a[n][j];
        for (int i = n-1; i >= 1; i--){
            down[i][j] = max(down[i+1][j], dp[i][j-1]) + a[i][j];
        }
        for (int i = 1; i <= n; i++){
            dp[i][j] = max(up[i][j], down[i][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}