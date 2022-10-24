#include <cstdio>
#include <algorithm>

using namespace std;

int a[2][100005][4];
int x[100005], y[100005];
int n, m, ans;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &y[i]);
	for (int i = 1; i <= n; i++)	{
		a[i&1][y[i]][0] = (a[i&1][y[i]][0] + x[i]*i) % 10007;
		a[i&1][y[i]][1] = (a[i&1][y[i]][1] + i) % 10007;
		a[i&1][y[i]][2] = (a[i&1][y[i]][2] + x[i]) % 10007;
		a[i&1][y[i]][3]++;
	}
	for (int j = 0; j <= 1; j++)
		for (int i = 1; i <= m; i++)
			ans = (ans + (a[j][i][1] * a[j][i][2]) % 10007 + (a[j][i][0]*(a[j][i][3]-2)) % 10007) % 10007;
	printf("%d", ans);
	return 0;
}
