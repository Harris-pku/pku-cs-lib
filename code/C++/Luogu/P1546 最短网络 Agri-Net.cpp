#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct Edge{
	int u, v, w;
    bool operator < (const Edge & x) const{
        return w < x.w;
    }
}edge[10005];
int fa[105], n, m, tot, ans, cur;
int found(int x){
	if (fa[x] == x) return x;
	return fa[x] = found(fa[x]);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            scanf("%d", &cur);
            if (i <= j) continue;
            edge[++m].u = i; edge[m].v = j; edge[m].w = cur;
        }
    }
    sort(edge+1, edge+m+1);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i){
		int fx = found(edge[i].u);
		int fy = found(edge[i].v);
	 	if (fx != fy){
			fa[fx] = fy; ans += edge[i].w;
            if (++tot == n-1){
                break;
            }
		}
	}
    printf("%d", ans);
	return 0;
}
