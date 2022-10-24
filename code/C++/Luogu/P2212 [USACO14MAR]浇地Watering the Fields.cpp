#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int inf = 0x3f3f3f3f;
int x[2005], y[2005], dis[2005], v[2005], n, m, ans;
int d(int i, int j){
    int cur = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
    if (cur < m) return inf; else return cur;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for (int i = 1; i <= n; ++i){
        int minn = 0, minm = inf;
        for (int j = 1; j <= n; ++j)
            if (!v[j])
                if (minm > dis[j]){
                    minn = j; minm = dis[j];
                }
        if (!minn){
            printf("-1"); return 0;
        }
        ans += minm; v[minn] = 1;
        for (int j = 1; j <= n; ++j)
            if (!v[j])
                dis[j] = min(dis[j], d(minn, j));
    }
    printf("%d", ans);
    return 0;
}