/*  Coder: Harris
    Time: 2020.2.2
    Website: https://www.luogu.com.cn/problem/P3956
    Algorithm: dfs
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int hx[] = {1, -1, 0, 0};
const int hy[] = {0, 0, 1, -1};
const int inf = 0x3f3f3f3f;
int f[105][105], a[105][105];
int n, m, bef, ans = inf;
void dfs(int x, int y, int cur, int t){
    if (x==n && y==n){
        ans = min(ans, cur); return;
    }
    if (ans < cur) return;
    if (cur >= f[x][y]) return;
    f[x][y] = cur;
    for (int i = 0; i < 4; i++){
        int xx = x + hx[i];
        int yy = y + hy[i];
        if (xx<1 || xx>n || yy<1 || yy>n) continue;
        if (a[x][y] == a[xx][yy]){
            dfs(xx, yy, cur, 0);
        }
        else if (a[xx][yy]){
            dfs(xx, yy, cur+1, 0);
        }
        else{
            if (t) continue;
            a[xx][yy] = a[x][y];
            dfs(xx, yy, cur+2, 1);
            a[xx][yy] = 0;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = z+1;
    }
    dfs(1, 1, 0, 0);
    printf("%d", ans==inf ? -1 : ans);
    return 0;
}
/*
input:
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0

output:
8
*/