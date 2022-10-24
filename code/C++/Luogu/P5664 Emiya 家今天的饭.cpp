#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int mod = 998244353;
int a[105][2005], sum[105][2005], n, m;
long long f[105][205], g[105][105] = {1}, ans;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n ; ++i)
		for (int j = 1; j <= m; ++j){
			scanf("%d", &a[i][j]);
			sum[i][0] = (sum[i][0]+a[i][j]) % mod;
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			sum[i][j] = (sum[i][0]-a[i][j]+mod) % mod;
	for (int k = 1; k <= m; ++k){
		memset(f, 0, sizeof(f)); f[0][n] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = n-i; j <= n+i; ++j)
				f[i][j] = (f[i-1][j] + f[i-1][j-1]*a[i][k]%mod + f[i-1][j+1]*sum[i][k]%mod) % mod;
		for (int i = 1; i <= n; ++i)
			ans = (ans + f[n][n+i]) % mod;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			g[i][j] = (g[i-1][j] + g[i-1][j-1]*sum[i][0]%mod) % mod;
	for (int i = 1; i <= n; ++i)
		ans = (ans-g[n][i]+mod) % mod;
	cout << ans*(mod-1)%mod << endl;
	return 0;
}