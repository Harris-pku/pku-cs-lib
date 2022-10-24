#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


int a[205][205], ti[205], n, m, t, x, y, z, cur, ans;
inline void update(int k){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = a[j][i] = min(a[i][j], a[i][k]+a[k][j]);
}
int main(){
	scanf("%d%d", &n, &m);
	memset(a, 0x3f, sizeof(a));
    for (int i = 0; i < n; ++i){
        scanf("%d", &ti[i]); a[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = a[y][x] = z;
    }
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i){
        scanf("%d%d%d", &x, &y, &z);
        while (ti[cur]<=z && cur<n){
            update(cur); cur++;
        }
        if (ti[x]>z || ti[y]>z || a[x][y]==0x3f3f3f3f){
            printf("-1\n"); continue;
        }
        else printf("%d\n", a[x][y]);
    }
	return 0;
}
