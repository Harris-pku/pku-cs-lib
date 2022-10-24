#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int dp[100010][25][5], n, m, f[500], ans;
char c;
int main(){
	scanf("%d%d", &n, &m);
	f['P'] = 0;	f['R'] = 1; f['S'] = 2;
	for (int i = 1; i <= n; i++){
		cin >> c;
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= 2; k++){
				if (f[c]-k == 2 || f[c]-k == -1)
					dp[i][j][k]++;
				dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
				dp[i+1][j+1][(k+2)%3] = max(dp[i+1][j+1][(k+2)%3], dp[i][j][k]);
				dp[i+1][j+1][(k+1)%3] = max(dp[i+1][j+1][(k+1)%3], dp[i][j][k]);
				if (i == n){
					ans = max(ans, dp[i][j][k]);
				}
			}
	}
	printf("%d", ans);
	return 0;
}
