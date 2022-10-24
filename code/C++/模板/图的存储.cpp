#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1005;
const int maxm = 10005;
int a[maxn][maxn], n, m, x, y, z;
int v[maxm], w[maxm], nex[maxm], h[maxn];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = a[y][x] = z;

        v[i] = y; w[i] = z;
        nex[i] = h[x]; h[x] = i;
        v[m+i] = x; w[m+i] = z;
        nex[m+i] = h[y]; h[y] = m+i;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = n; j >= 1; --j){
            if (a[i][j]) 
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= n; ++i){
        int p = h[i];
        while (p){
            printf("%d ", w[p]);
            p = nex[p];
        }
        printf("\n");
    }
    
    return 0;
}