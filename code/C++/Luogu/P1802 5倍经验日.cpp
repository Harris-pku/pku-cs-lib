#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[1005], lose[1005], win[1005], use[1005], n, m;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &lose[i], &win[i], &use[i]);
    for (int i = 1; i <= n; ++i){
        for (int j = m; j >= use[i]; --j)
            dp[j] = max(dp[j] + lose[i], dp[j-use[i]] + win[i]);
        for (int j = use[i] - 1; j >= 0; --j)
            dp[j] += lose[i];
    }
    printf("%lld", 5ll * dp[m]);
    return 0;
}