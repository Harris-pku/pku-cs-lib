#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int v[200010], nex[200010], h[100010];
int dp[100010], n, m, x, y;
void dfs(int t){
	if (dp[t]) return;
	int p = h[t];
	dp[t] = 1;
	while (p){
		dfs(v[p]);
		dp[t] = max(dp[t], dp[v[p]] + 1);
		p = nex[p];
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &x, &y);
		v[i] = x;
		nex[i] = h[y];
		h[y] = i;
	}
	for (int i = 1; i <= n; i++){
		dfs(i);
		printf("%d\n", dp[i]);
	}
	return 0;
}
