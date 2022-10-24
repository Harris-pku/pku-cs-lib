#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int a[2505][2505], f[2505][2505], h[2505][2505], l[2505][2505];
int n, m, ans;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            scanf("%d", &a[i][j]);
            if (!a[i][j]){
                h[i][j] = h[i][j-1] + 1;
                l[i][j] = l[i-1][j] + 1;
            }
            else
                f[i][j] = min(f[i-1][j-1], min(h[i][j-1], l[i-1][j])) + 1;
            ans = max(ans, f[i][j]);
        }
    memset(f, 0, sizeof(f));
    memset(h, 0, sizeof(h));
    memset(l, 0, sizeof(l));
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 1; --j){
            if (!a[i][j]){
                h[i][j] = h[i][j+1] + 1;
                l[i][j] = l[i-1][j] + 1;
            }
            else
                f[i][j] = min(f[i-1][j+1], min(h[i][j+1], l[i-1][j])) + 1;
            ans = max(ans, f[i][j]);
        }
    printf("%d", ans);
    return 0;
}