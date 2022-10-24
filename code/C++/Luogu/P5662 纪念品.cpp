#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int f[10005], a[105][105], n, m, t;
int main(){
    scanf("%d%d%d", &t, &n, &m);
    for (int i = 1; i <= t; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i < t; ++i){
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= n; ++j){
            for (int k = a[i][j]; k <= m; ++k){
                f[k] = max(f[k], f[k-a[i][j]] + a[i+1][j] - a[i][j]);
            }
        }
        m += f[m];
    }
    printf("%d", m);
    return 0;
}