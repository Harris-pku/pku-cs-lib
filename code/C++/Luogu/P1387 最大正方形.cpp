#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a[105][105], f[105][105], n, m, ans;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            scanf("%d", &a[i][j]);
            if (a[i][j]) 
                f[i][j] = min(min(f[i][j-1], f[i-1][j]), f[i-1][j-1]) + 1;
            ans = max(ans, f[i][j]);
        }
    printf("%d", ans);
    return 0;
}