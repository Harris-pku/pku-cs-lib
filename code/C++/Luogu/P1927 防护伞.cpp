#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int x[1010], y[1010], n, t, maxn, ans = 0x7fffffff;
inline int solve(int a, int b){
	return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++){
		maxn = 0;
		for (int j = 1; j <= n; j++){
			t = solve(i, j);
			maxn = max(maxn, t);
		}
		ans = min(ans, maxn);
	}
	printf("%.4f", 3.1415926535 * ans);
	return 0;
}
