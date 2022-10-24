#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int p = 1e9 + 7;
long long a[105][105], ans[105][105], n, k;
long long x[105][105], y[105][105];
void pow(long long cur[105][105]){
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            x[i][j] = cur[i][j];
            y[i][j] = a[i][j];
            cur[i][j] = 0;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                cur[i][j] = (cur[i][j] + x[i][k]*y[k][j]%p) % p;
}
int main(){
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            scanf("%lld", &a[i][j]);
            ans[i][j] = a[i][j];
        }
    }
    k--;
    while(k){
        if (k&1) pow(ans);
        pow(a);
        k >>= 1;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
