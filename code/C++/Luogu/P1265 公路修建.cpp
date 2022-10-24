#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#define INF 0x3f3f3f3f

using namespace std;

double dis[5005], ans; int vis[5005];
int x[5005], y[5005], n, m, tot, z;
inline double cal(int a, int b){
    return sqrt((double)(x[a] - x[b]) * (x[a] - x[b]) + (double)(y[a] - y[b]) * (y[a] - y[b]));
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d", &x[i], &y[i]);
        if (i != 1) dis[i] = INF;
    }
    for (int k = 1; k <= n; ++k){
        double mincost = INF; int minpo = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i] && dis[i]<mincost){
                mincost = dis[i]; minpo = i;
            }
        ans += mincost; vis[minpo] = 1;
        for (int i = 1; i <= n; ++i){
            double d = cal(minpo, i);
            if (d < dis[i]) dis[i] = d;
        }
    }
    printf("%.2f", ans);
    return 0;
}
