#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[20010], d[20010], k[20010], f[20010], len, s, t, n, x, ans = 1000000;
int main(){
	scanf("%d%d%d%d", &len, &s, &t, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	x = t * (t + 1);
	a[n + 1] = len;
	for (int i = 1; i <= n + 1; i++){
		d[i] = a[i] - a[i - 1];
		if (d[i] > x)
			d[i] = d[i] % x + x;
	}
	for (int i = 1; i <= n; i++)
		k[a[i] = a[i - 1] + d[i]] = 1;
	len = a[n] + d[n + 1];
	memset(f, 6, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= len + t; i++)
		for (int j = s; j <= t; j++)
			if (i >= j)
			{
				if (k[i - j])
					f[i] = min(f[i], f[i - j] + 1);
				else
					f[i] = min(f[i], f[i - j]);
			}
	for (int i = len; i <= len + t; i++)
		ans = min(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
