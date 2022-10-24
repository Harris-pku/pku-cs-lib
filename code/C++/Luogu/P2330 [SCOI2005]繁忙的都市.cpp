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
}edge[200010];
int fa[10010], n, m, tot;
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
			fa[fx] = fy;
            if (++tot == n-1){
                printf("%d %d", n-1, edge[i].w); break;
            }
		}
	}
	return 0;
}
