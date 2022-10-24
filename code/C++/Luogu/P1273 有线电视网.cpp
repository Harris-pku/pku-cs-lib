#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
	int to, w, nex;
}e[3005];
int dp[3005][3005], a[3005], h[3005], t[3005];
int n, m, num, x, w, cnt;
int dfs(int u){
	if (u > n-m){
		dp[u][1] = a[u]; return 1;
	}
	int sum = 0;
	for (int p = h[u]; p; p = e[p].nex){
		int v = e[p].to; int tk = dfs(v);
		for (int i = 0; i <= sum; i++)
			t[i] = dp[u][i];
		for (int i = 0; i <= sum; i++)
			for (int j = 0; j <= tk; j++)
				dp[u][i+j] = max(dp[u][i+j], t[i] + dp[v][j] - e[p].w);
		sum += tk;
	}
	return sum;
}
int main(){
	scanf("%d%d", &n, &m);
	memset(dp, ~0x3f, sizeof(dp));
	for (int u = 1; u <= n-m; u++){
		scanf("%d", &num);
		for (int i = 1; i <= num; i++){
			scanf("%d%d", &x, &w);
			e[++cnt].to = x; e[cnt].w = w;
			e[cnt].nex = h[u]; h[u] = cnt;
		}
	}
	for (int i = n-m+1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		dp[i][0] = 0;
	dfs(1);
	for (int i = m; i > 0; i--){
		if (dp[1][i] >= 0){
			printf("%d", i); break;
		}
	}
	return 0;
}