#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
	int start, arrive, end;
} a[100005];
int time[100005], f[100005], g[100005], d[100005], sum[100005];
int n, m, k, t, h, ans;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i < n; i++)
		scanf("%d", &d[i]);
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &a[i].arrive, &a[i].start, &a[i].end);
		f[a[i].start] = max(f[a[i].start], a[i].arrive);
		sum[a[i].end]++;
	}
	for (int i = 2; i <= n; i++)
		sum[i] += sum[i - 1];
	for (int i = 2; i <= n; i++)
		time[i] = max(time[i - 1], f[i - 1]) + d[i - 1];
	for (int i = 1; i <= m; i++)
		ans += time[a[i].end] - a[i].arrive;
	while (k){
		g[n] = g[n - 1] = n; t = 0;
		for (int i = n - 2; i; i--){
			if (time[i + 1] <= f[i + 1])
				g[i] = i + 1;
			else
				g[i] = g[i + 1];
		}
		for (int i = 1; i <= n; i++)
			if (sum[g[i]] - sum[i] > t && d[i] > 0)
				t = sum[g[i]] - sum[i], h = i;
		if (!t)
			break;
		ans -= t; d[h]--; k--;
		time[1] = 0;
		for (int i = 2; i <= n; i++)
			time[i] = max(time[i - 1], f[i - 1]) + d[i - 1];
	}
	printf("%d", ans);
	return 0;
}
