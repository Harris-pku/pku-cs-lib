#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[105][105], n, s, t, k, cur;
int main(){
    scanf("%d%d%d", &n, &s, &t);
    memset(a, 0x3f, sizeof(a));
    for (int i = 1; i <= n; ++i) a[i][i] = 0;
    for (int i = 1; i <= n; ++i){
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j){
            scanf("%d", &cur);
            if (j == 1) a[i][cur] = 0;
            else a[i][cur] = 1;
        }
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    if (a[s][t] == 0x3f3f3f3f) printf("-1");
    else printf("%d", a[s][t]);
    return 0;
}