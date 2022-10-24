#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int color[maxn];

bool bipartite(int u) {
	for (int i=0;i<G[u].size();i++) {
		int v = G[u][i];
		if (color[v] == color[u]) return false;
		if (!color[v]) {
			color[v] = 3 - color[u];
			if (!bipartite(v)) return false;
		}
	}
	return true;
} 

