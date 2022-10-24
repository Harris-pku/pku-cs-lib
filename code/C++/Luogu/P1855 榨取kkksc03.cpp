#include <cstdio>
#include <algorithm>

using namespace std;

int f[205][205];
int n, m, t, v, w;
int main(){
	scanf("%d%d%d", &n, &m, &t);
	for (int k = 1; k <= n; k++){
		scanf("%d%d", &v, &w);
		for (int i = m; i >= v; i--)
			for (int j = t; j >= w; j--)
				f[i][j] = max(f[i][j], f[i - v][j - w] + 1);
	}
	printf("%d", f[m][t]);
	return 0;
}
