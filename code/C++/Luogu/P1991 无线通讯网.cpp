#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

struct edge{
	int u, v; double w;
	bool operator < (const edge & x) const{
		return w < x.w;
	}
}edge[1000005];
int fa[505], n, m, tot, s; double x[505], y[505], ans;
int found(int x){
	if (fa[x] == x) return x;
	return fa[x] = found(fa[x]);
}
double dis(int a, int b){
    return sqrt((x[a]-x[b]) * (x[a]-x[b]) + (y[a]-y[b]) * (y[a]-y[b]));
}
int main(){
	scanf("%d%d", &s, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", &x[i], &y[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = i+1; j <= n; ++j){
            edge[++m].u = i; edge[m].v = j; edge[m].w = dis(i, j);
        }
	sort(edge+1, edge+m+1);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i){
		int fx = found(edge[i].u);
		int fy = found(edge[i].v);
	 	if (fx != fy){
			fa[fx] = fy;
			if (++tot == n-s){
				ans = edge[i].w; break;
			}
		}
	}
	printf("%.2f", ans);
	return 0;
}
