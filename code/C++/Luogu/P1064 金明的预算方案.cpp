#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 65;
const int maxv = 32005;
int f[maxv], v[maxn], w[maxn], p[maxn][3], n, m, t;
int main(){
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d%d", &v[i], &w[i], &t);
		w[i] *= v[i];
		if (t){
			p[t][++p[t][0]] = i;
			p[i][0] = -1;
		}
	}
	for (int i = 1; i <= n; i++){
		if (p[i][0] == -1)
			continue;
		for (int j = m; j >= 0; j--){
			if (j - v[i] >= 0){
				f[j] = max(f[j], f[j - v[i]] + w[i]);
			}
			if (j - v[i] - v[p[i][1]] >= 0){
				f[j] = max(f[j], f[j - v[i] - v[p[i][1]]] + w[i] + w[p[i][1]]);
			}
			if (j - v[i] - v[p[i][2]] >= 0){
				f[j] = max(f[j], f[j - v[i] - v[p[i][2]]] + w[i] + w[p[i][2]]);
			}
			if (j - v[i] - v[p[i][1]] - v[p[i][2]] >= 0){
				f[j] = max(f[j], f[j - v[i] - v[p[i][1]] - v[p[i][2]]] + w[i] + w[p[i][1]] + w[p[i][2]]);
			}
		}
	}
	printf("%d", f[m]);
	return 0;
}
