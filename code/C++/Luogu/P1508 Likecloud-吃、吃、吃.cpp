#include <cstdio>
#include <algorithm>

using namespace std;

int a[205][205], f[205][205], m, n, ans;
int main(){
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		f[1][i] = a[1][i];
	for (int i = 2; i <= m; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = max(f[i - 1][j - 1], max(f[i - 1][j], f[i - 1][j + 1])) + a[i][j];
	ans = max(f[m][n / 2], max(f[m][n / 2 + 1], f[m][n / 2 + 2]));
	printf("%d", ans);
	return 0;
}
