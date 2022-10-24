#include <cstdio>
#include <algorithm>

using namespace std;

char c; int a[1005][1005], n, m, ans;
int h[5][2] = {0, 0, 0, 1, 1, 0, 0, -1, -1, 0};
int main(){
	scanf("%d%d\n", &n, &m);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%c", &c);
			a[i][j] = c - '0';
		}
		scanf("\n");
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			if (a[i][j])
				ans += 2;
			for (int k = 1; k <= 4; k++)
				if (a[i][j] > a[i + h[k][0]][j + h[k][1]])
					ans += a[i][j] - a[i + h[k][0]][j + h[k][1]];
		}
	printf("%d", ans);
	return 0;
}
