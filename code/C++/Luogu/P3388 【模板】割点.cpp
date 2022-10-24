#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

const int maxn = 100010;
using namespace std;

int iscut[maxn], pre[maxn], low[maxn];
int n, m, x, y, cnt, dfs_clock;
vector<int> G[maxn];

int dfs(int u, int fa) {
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for (int i = 0;i < G[u].size();i++) {
		int v = G[u][i];
		if (!pre[v]) {
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= pre[u]) iscut[u] = true;
		}
		else if (pre[v] < pre[u] && v!=fa) 
	         lowu = min(lowu, pre[v]);
	}
	if (fa < 0 && child == 1) iscut[u] = 0;
	low[u] = lowu;
	return lowu;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y); G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!pre[i]) dfs(i, -1);
	}
	for (int i = 1; i <= n; i++)
		if (iscut[i]){
			++cnt; G[0].push_back(i);
		}
	printf("%d\n", cnt);
	for (int i = 0; i < G[0].size(); i++) {
		printf("%d ", G[0][i]);
	}
	return 0;
}
