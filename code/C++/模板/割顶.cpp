#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int dfs(int u, int fa) {
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for (int i = 0;i < G[u].size();i++) {
		int v = G[u][i];
		if (!pre[v]) {
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= lowu) iscut[u] = true;
		}
		else if (pre[v] < pre[u] && v!=fa) 
	         lowu = min(lowu, pre[v]);
	}
	if (fa < 0 && child == 1) iscut[u] = 0;
	low[u] = lowu;
	return lowu;	
}


