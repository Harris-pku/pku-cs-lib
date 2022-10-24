#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int hx[4] = {0, 1, 0, -1};
const int hy[4] = {1, 0, -1, 0};
int vis[1505][1505][3], mapx[1505][1505], n, m, ans, sx, sy;
char c;
void dfs(int x, int y, int px, int py){
    if (vis[px][py][2] && (vis[px][py][0]!=x || vis[px][py][1]!=y)){
        ans = 1; return;
    }
    if (vis[px][py][2] && vis[px][py][0]==x && vis[px][py][1]==y) return;
    vis[px][py][0] = x; vis[px][py][1] = y; vis[px][py][2] = 1;
    for (int k = 0; k <= 3; ++k){
        int tox = (px + hx[k] + n) % n;
        int toy = (py + hy[k] + m) % m;
        if (mapx[tox][toy]) dfs(x+hx[k], y+hy[k], tox, toy);
    }
}
int main(){
    while (cin >> n >> m){
        memset(vis, 0, sizeof(vis));
        memset(mapx, 0, sizeof(mapx));
        ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                cin >> c;
                if (c == '.') mapx[i][j] = 1;
                else if (c == 'S'){
                    sx = i; sy = j;
                    mapx[i][j] = 1;
                }
            }
        dfs(sx, sy, sx, sy);
        if (ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}