#include <cstdio>
#include <algorithm>

using namespace std;

int f[205][205], a[205][3], n, b, c, h, ans;
int main(){
	scanf("%d%d", &n, &b);
	for (int j = 1; j <= n - 1; j++){
		scanf("%d", &c);
		a[j][1] = b; a[j][2] = c; b = c;
	}
	a[n][1] = b; a[n][2] = a[1][1];
	for (int j = n + 1; j <= 2 * n; j++){
		a[j][1] = a[j - n][1];
		a[j][2] = a[j - n][2];
	}
	for (int j = 1; j < n; j++){
		for (int i = 1; i < n * 2; i++){
			if (i + j > n * 2)
				break;
			for (int k = i; k < i + j; k++){
				f[i][i + j] = max(f[i][i + j], f[i][k] + f[k + 1][i + j] + a[i][1] * a[k][2] * a[i + j][2]);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		ans = max(ans, f[i][i + n - 1]);
	}
	printf("%d", ans);
	return 0;
}
