#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct trash{
    int t, h, f;
    bool operator < (const trash & x) const{
        return t < x.t;
    }
}a[105];
int dp[105] = {10}, n, m;
int main(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i].t, &a[i].f, &a[i].h);
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i){
        for (int j = m; j >= 0; --j){
            if (dp[j] >= a[i].t){
                if (j+a[i].h >= m){
                    printf("%d", a[i].t); return 0;
                }
                dp[j+a[i].h] = max(dp[j+a[i].h], dp[j]);
                dp[j] += a[i].f;
            }
        }
    }
    printf("%d", dp[0]);
    return 0;
}