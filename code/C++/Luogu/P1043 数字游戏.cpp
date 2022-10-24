#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[110], f[110][110][15], g[110][110][15];
int c[110], n, m, minn = 0x7ffffff, maxn;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[n + i] = a[i];
	}
	for (int i = 1; i <= n * 2; i++)
		c[i] = c[i - 1] + a[i];
	memset(g, 1, sizeof(g));
	for (int i = 1; i <= n * 2; i++){
		f[i][i][1] = g[i][i][1] = (a[i] % 10 + 10) % 10;
	}
	for (int i = 1; i <= n * 2; i++)
		for (int j = i + 1; j <= n * 2; j++){
			f[i][j][1] = ((f[i][j - 1][1] + a[j]) % 10 + 10) % 10;
			g[i][j][1] = ((g[i][j - 1][1] + a[j]) % 10 + 10) % 10;
		}
	for (int k = 2; k <= m; k++)
		for (int i = 1; i <= n * 2; i++)
			for (int j = i + k - 1; j <= n * 2; j++)
				for (int l = i + k - 1; l <= j; l++){
					f[i][j][k] = max(f[i][j][k], f[i][l - 1][k - 1] * (((c[j] - c[l - 1]) % 10 + 10) % 10));
					g[i][j][k] = min(g[i][j][k], g[i][l - 1][k - 1] * (((c[j] - c[l - 1]) % 10 + 10) % 10));
				}
	for (int i = 1; i <= n; i++){
		maxn = max(maxn, f[i][n + i - 1][m]);
		minn = min(minn, g[i][n + i - 1][m]);
	}
	printf("%d\n%d\n", minn, maxn);
	return 0;
}
