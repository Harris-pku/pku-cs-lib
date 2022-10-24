#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[205][205], g[205][205];
int sum[205], a[205], n, maxn, minn = 0x3f3f3f3f;
int main(){
    scanf("%d", &n); memset(g, 1, sizeof(g));
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i]; g[i][i] = 0;
    }
    for (int i = n+1; i <= 2*n; ++i){
        a[i] = a[i-n];
        sum[i] = sum[i-1] + a[i]; g[i][i] = 0;
    }
    for (int j = 1; j <= n-1; ++j){
        for (int i = 1; i <= 2*n; ++i){
            if (i+j > 2*n) break;
            for (int k = 0; k < j; ++k){
                f[i][i+j] = max(f[i][i+j], f[i][i+k] + f[i+k+1][i+j]);
                g[i][i+j] = min(g[i][i+j], g[i][i+k] + g[i+k+1][i+j]);
            }
            f[i][i+j] += sum[i+j] - sum[i-1];
            g[i][i+j] += sum[i+j] - sum[i-1];
        }
    }
    for (int i = 1; i <= n; ++i){
        maxn = max(maxn, f[i][i+n-1]);
        minn = min(minn, g[i][i+n-1]);
    }
    printf("%d\n%d\n", minn, maxn);
    return 0;
}
