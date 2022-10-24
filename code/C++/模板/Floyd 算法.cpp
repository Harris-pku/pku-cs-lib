#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[1005][1005], n, m, s, t, x, y;
int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(a, 0x3f, sizeof(a));
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        scanf("%d", &a[x][y]);
    }
    for (int k = 1; k <= n; ++k)
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            if (a[i][j] > a[i][k] + a[k][j])
                a[i][j] = a[i][k] + a[k][j];
        }
    printf("%d", a[s][t]);
    return 0;
}