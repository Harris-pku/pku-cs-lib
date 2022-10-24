#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct edge{
	int u, v, w;
	bool operator < (const edge & x) const{
		return w < x.w;
	}
}edge[200005];
int fa[10005], n, m, tot, ans;
int found(int x){
	if (fa[x] == x) return x;
	return fa[x] = found(fa[x]);
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	sort(edge+1, edge+m+1);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i){
		int fx = found(edge[i].u);
		int fy = found(edge[i].v);
	 	if (fx != fy){
			fa[fx] = fy; ans += edge[i].w;
			if (++tot == n-1) break;
		}
	}
	tot = found(1);
	for (int i = 2; i <= n; ++i)
	 	if (found(i) != tot){
			printf("not one"); return 0;
		}
	printf("%d", ans);
	return 0;
}
