#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
int a[105][105], dis[105][105], c[105], n, k, m, s, t, x, y, z;
int main(){
	scanf("%d%d%d%d%d", &n, &k, &m, &s, &t);
	memset(dis, 6, sizeof(dis));
	for (int i = 1; i <= n; ++i)
	    scanf("%d", &c[i]);
	for (int i = 1; i <= k; ++i)
	    for (int j = 1; j <= k; ++j)
	        scanf("%d", &a[i][j]);
	for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", &x, &y, &z);
	    if (dis[x][y] < z) continue;
	    dis[x][y] = dis[y][x] = z;
	}
	for (int i = 1; i <= n; ++i)
	    for (int j = 1; j <= n; ++j)
	        if (a[c[i]][c[j]]) dis[j][i] = 101058054;
	for (int k = 1; k <= n; ++k)
	    for (int i = 1; i <= n; ++i)
	        for (int j = 1; j <= n; ++j)
	            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	if (dis[s][t] == 101058054) printf("-1\n");
	else printf("%d\n", dis[s][t]);
	return 0;
}