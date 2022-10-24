#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int a[1005][1005], v[100005], c[100005], dp[100005];
int n, m, t, e, tot, k;
int main(){
    scanf("%d%d%d%d", &n, &m, &t, &e);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            scanf("%d", &k);
            int t = 1, x = 2*(i+j);
            if (a[i][j]){
                while (k >= t){
                    c[++tot] = t*x;
                    v[tot] = t*a[i][j];
                    k -= t; t <<= 1;
                }
                c[++tot] = x*k;
                v[tot] = k*a[i][j]; 
            }
        }
    t = min(t, e-1);
    for (int i = 1; i <= tot; ++i)
        for (int j = t; j >= c[i]; --j)
            dp[j] = max(dp[j], dp[j-c[i]] + v[i]);
    printf("%d", dp[t]);
    return 0;
}
