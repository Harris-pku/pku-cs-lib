#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct Node{
	int u, v, w;
}edge[200010];
int fa[10010], n, m, tot, ans;
int cmp(Node a, Node b){
	return a.w < b.w;
}
int found(int x){
	if (fa[x] == x) return x;
	return fa[x] = found(fa[x]);
}
int main(){
	scanf("%d%d", &n, &m); tot = n;
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	sort(edge+1, edge+m+1, cmp);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i<=m && tot>1; ++i){
		int x = found(edge[i].u);
		int y = found(edge[i].v);
	 	if (x != y){
			fa[x] = y; ans += edge[i].w; tot--;
		}
	}
	tot = found(1);
	for (int i = 2; i <= n; ++i)
	 	if (found(i) != tot){
			printf("orz"); return 0;
		}
	printf("%d",ans);
	return 0;
}
