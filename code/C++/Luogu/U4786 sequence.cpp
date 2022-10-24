#include <cstdio>
#include <algorithm>

using namespace std;

int a[100005], f[100005][3];
int n, m, p, q, l, r, x, y, ans;
int main(){
	scanf("%d%d%d%d", &n, &m, &p, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &f[i][1], &f[i][2]);
	for (int k = 1; k <= q; k++){
		scanf("%d%d", &x, &y);
		a[x] = y; ans = 0;
		for (int j = 1; j <= m; j++){
			l = f[j][1]; r = f[j][2];
			for (int i = l; i <= r; i++){
				if (a[i] < p)
					continue;
				else{
					ans++; break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
