#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 0x7ffffff;
int up[10005], down[10005], guan[10005], lu[10005][2], dp[2][10005];
int n, m, k, x, f1, ans, cnt;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &up[i], &down[i]);
		lu[i][1] = m + 1;
	}
	lu[n][1] = m + 1;
	for (int i = 1; i <= k; i++){
		scanf("%d", &x);
		scanf("%d%d", &lu[x][0], &lu[x][1]);
		guan[i] = x;
	}
	sort(guan+1, guan+k+1);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			dp[i & 1][j] = inf;
		for (int j = lu[i][0] + 1; j < lu[i][1]; j++){
			if (j - up[i - 1] > lu[i - 1][0])
				dp[i & 1][j] = min(dp[i & 1][j], min(dp[(i - 1) & 1][j - up[i - 1]], dp[i & 1][j - up[i - 1]]) + 1);
			if (j == m)
				for (int x = m - up[i - 1]; x <= m; x++)
					dp[i & 1][j] = min(dp[i & 1][j], min(dp[(i - 1) & 1][x], dp[i & 1][x]) + 1);
			if (j + down[i - 1] > lu[i - 1][0] && j + down[i - 1] < lu[i - 1][1])
				dp[i & 1][j] = min(dp[i & 1][j], dp[(i - 1) & 1][j + down[i - 1]]);
		}
		f1 = 1;
		for (int j = lu[i][0] + 1; j < lu[i][1]; j++)
			if (dp[i & 1][j] < inf){
				f1 = 0; break;
			}
		if (f1){
			cnt = i - 1; break;
		}
	}
	if (f1){
		for (int i = 1; i <= k; i++)
			if (guan[i] > cnt){
				cnt = i - 1; break;
			}
		printf("0\n%d", cnt);
	}
	else{
		ans = inf;
		for (int i = lu[n][0] + 1; i < lu[n][1]; i++)
			ans = min(ans, dp[n & 1][i]);
		printf("1\n%d", ans);
	}
	return 0;
}
