#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int f[25], a[25], n, k, ans, sum;
int prime(int x){
	if (x <= 1) return 0;
	int m = floor(sqrt(x));
	for (int i = 2; i <= m; i++){
		if (x % i == 0){
			return 0;
		}
	}
	return 1;
}
void dfs(int cur, int tot){
	if (tot == k && sum >= 2 && prime(sum)){
		ans++; return;
	}
	if (tot >= k) return;
	for (int i = cur + 1; i <= n; i++){
		if (f[i]) continue;
		f[i] = 1; sum += a[i];
		dfs(i, tot + 1);
		f[i] = 0; sum -= a[i];
	}
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
