#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int hx[8] = {1, 1, -1, -1};
const int hy[8] = {1, -1, 1, -1};
struct point{
    int x, y;
    point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
}q[10005], cur;
int a[35][35], vis[35][35], dis[35][35];
int n, m, m1[2], m2[2], x0, y0, x1, y1, head, tail;
int main(){
    scanf("%d%d%d%d", &n, &m, &m1[0], &m2[0]);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);
            if (a[i][j] == 3){
                x0 = i; y0 = j;
            }
            else if (a[i][j] == 4){
                x1 = i; y1 = j;
            }
        }
    }
    m1[1] = m2[0]; m2[1] = m1[0];
    memset(dis, 0x3f, sizeof(dis));
    q[head] = point(x0, y0); tail = 1;
    vis[x0][y0] = 1; dis[x0][y0] = 0;
    while (head < tail){
        cur = q[head++]; vis[cur.x][cur.y] = 0;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 2; j++){
                int xx = cur.x + hx[i]*m1[j];
                int yy = cur.y + hy[i]*m2[j];
                if (xx<1 || xx>n || yy<1 || yy>m || a[xx][yy]==0 || a[xx][yy]==2) continue;
                if (dis[xx][yy] > dis[cur.x][cur.y] + 1){
                    dis[xx][yy] = dis[cur.x][cur.y] + 1;
                    if (!vis[xx][yy]){
                        q[tail++] = point(xx, yy); vis[xx][yy] = 1;
                    }
                }
            }
        }
    }
    printf("%d\n", dis[x1][y1]);
    return 0;
}
