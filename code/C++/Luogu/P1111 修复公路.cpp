/*  Coder: Harris
    Time: 2019.8.19
    Website: https://www.luogu.com.cn/problem/P1111
    Description: n points and m edges, given the information of every 
                 edge of u, v and t, t means when can this edge build,
                 when can this graph become a connected graph?
                 给定 n 点 m 边, 每条边的起点, 终点, 连通时间, 问图何时连通
    
    Algorithm: use Union-Find to record the number of connected section
               并查集记录联通块个数, 当整张图形成一个联通块时全图连通
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct edge{
    int u, v, t;
    bool operator < (const edge & x) const{
        return t < x.t;
    }
}a[100005];
int fa[1005], n, m, cur, tot;
int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].t);
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    sort(a+1, a+m+1);
    for (int i = 1; i <= m; i++){
        int fx = found(a[i].u);
        int fy = found(a[i].v);
        if (fx != fy){
            fa[fx] = fy;
            if (++tot == n-1){
                printf("%d", a[i].t); return 0;
            }
        }
    }
    printf("-1");
    return 0;
}
/*
input:
4 4
1 2 6
1 3 4
1 4 5
4 2 3

output:
5
*/