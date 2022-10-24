#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int v[505], w[505], a[105], b[105], dp[5005][105];
int n, m, t, x, y, z, ans;
int main(){
	scanf("%d%d%d", &t, &m, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &v[i], &w[i]);
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= t; j++)
			dp[i][j] = -99999999;
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--){
			x = y = z = 1;
			for (int k = 1; k <= t; k++){
				a[k] = dp[j][k];
				b[k] = dp[j - v[i]][k] + w[i];
			}
			while (z <= t){
				if (a[x] > b[y] && x <= t)
					dp[j][z++] = a[x++];
				else if (a[x] <= b[y] && y <= t)
					dp[j][z++] = b[y++];
			}
		}
	for (int i = 1; i <= t; i++)
		ans += dp[m][i];
	printf("%d", ans);
	return 0;
}
