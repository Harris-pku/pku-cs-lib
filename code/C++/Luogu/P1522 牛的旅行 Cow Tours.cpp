#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int inf = 0x3f3f3f3f;
int x[155], y[155], n, cur;
double dis[155][155], maxd[155], l1, l2 = inf, ans;
double cal(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            scanf("%1d", &cur);
            if (cur) dis[i][j] = cal(i, j);
            else if (i != j) dis[i][j] = inf;
        }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            if (dis[i][j] != inf) maxd[i] = max(dis[i][j], maxd[i]);
            l1 = max(l1, maxd[i]);
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (dis[i][j] == inf)
                l2 = min(maxd[i]+cal(i, j)+maxd[j], l2);
    printf("%.6f", max(l1, l2));
    return 0;
}