#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstring>

using namespace std;

const int hx[4] = {0, 1, 0, -1};
const int hy[4] = {1, 0, -1, 0};
int a[105][105], b[105][105], n, m, ans;

int dfs(int x, int y){
    if (b[x][y] != -1) return b[x][y];
    int p = 1;
    for (int i = 0; i < 4; i++){
        int xx = x + hx[i];
        int yy = y + hy[i];
        if (xx<=n && xx>0 && yy<=m && yy>0 && a[xx][yy]<a[x][y])
	        p = max(dfs(xx, yy) + 1, p);
    }
    return b[x][y] = p;
}
int main(){
    scanf("%d%d", &n, &m);
    memset(b, -1, sizeof(b));
    for (int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++)
	        ans = max(dfs(i, j), ans);
    printf("%d", ans);
    return 0;
}
