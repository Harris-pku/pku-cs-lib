#include <cstdio>
#include <algorithm>

using namespace std;

int ttime[105], htime[105], fen[105], f[1005];
int n, m, k, r, ans;
int main(){
	scanf("%d%d%d%d", &n, &m, &k, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &ttime[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &htime[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &fen[i]);
	for (int i = 1; i <= m; i++)
		for (int j = r; j >= htime[i]; j--)
			f[j] = max(f[j], f[j - htime[i]] + fen[i]);
	for (int i = 1; i <= r; i++)
		if (f[i] >= k){
			r -= i;	break;
		}
	sort(ttime+1, ttime+n+1);
	for (int i = 1; i <= n; i++)
		if (r >= ttime[i]){
			ans++; r -= ttime[i];
		}
		else break;
	printf("%d", ans);
	return 0;
}
