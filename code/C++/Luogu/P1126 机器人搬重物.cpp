#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int MDIR[256], n, m, sx, sy, tx, ty, dir;
bool map[60][60], vis[60][60][4];
int d[60][60];
struct POS{
    int x, y, dir, t;
    int lx, ly, ldir, lt;
    POS(int _x = 0, int _y = 0, int _dir = -1) : x(_x), y(_y), dir(_dir), t(0){};
};
queue<POS> q;
bool inline check(const POS &p){
    return 1 <= p.x && p.x <= n && 1 <= p.y && p.y <= m;
}
void turn(const POS &s, POS &res, int c){
    res = s;
    switch (c){
        case 0:
            break;
        case 1:
            res.dir = res.dir - 1;
            res.t++;
            break;
        case 2:
            res.dir = res.dir + 1;
            res.t++;
            break;
    }
    while (res.dir < 0)
        res.dir += 4;
    while (res.dir > 3)
        res.dir -= 4;
}
bool move(POS &s, POS &res, int steps){
    res = s;
    switch (s.dir){
        case 0:
            res.y -= steps;
            break;
        case 1:
            res.x -= steps;
            break;
        case 2:
            res.y += steps;
            break;
        case 3:
            res.x += steps;
            break;
    }
    res.t++;
    return check(res) && !map[res.x][res.y];
}
int main(){
    MDIR['W'] = 0; MDIR['N'] = 1; MDIR['E'] = 2; MDIR['S'] = 3;
    scanf("%d%d", &n, &m);
    bool b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            scanf("%d", &b);
            for (int dx = 0; dx <= 1; dx++)
                for (int dy = 0; dy <= 1; dy++){
                    map[i+dx][j+dy] = map[i+dx][j+dy] || b;
                }
        }
    n++; m++;
    for (int i = 1; i <= m; i++)
        map[1][i] = 1;
    for (int i = 1; i <= m; i++)
        map[n][i] = 1;
    for (int i = 1; i <= n; i++)
        map[i][1] = 1;
    for (int i = 1; i <= n; i++)
        map[i][m] = 1;
    scanf("%d%d%d%d %c", &sx, &sy, &tx, &ty, &dir);
    sx++; sy++; tx++; ty++;
    POS p(sx, sy, MDIR[dir]);
    vis[sx][sy][MDIR[dir]] = 1;
    q.push(p);
    while (!q.empty()){
        p = q.front(); q.pop();
        if (p.x == tx && p.y == ty){
            printf("%d", p.t); return 0;
        }
        POS res;
        for (int i = 1; i <= 2; i++){
            turn(p, res, i);
            if (vis[res.x][res.y][res.dir])
                continue;
            vis[res.x][res.y][res.dir] = 1;
            q.push(res);
        }
        for (int steps = 1; steps <= 3; steps++)
            if (move(p, res, steps)){
                if (vis[res.x][res.y][res.dir])
                    continue;
                vis[res.x][res.y][res.dir] = 1;
                q.push(res);
            }
            else
                break;
    }
    printf("-1");
    return 0;
}
