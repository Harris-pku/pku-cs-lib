#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
int f[20], n, cur; double ans = 100000000.0, x[20], y[20];
void dfs(int la, double tot){
	if (tot > ans) return;
	if (cur == n){
		ans = min(ans, tot); return;
	}
	for (int i = 1; i <= n; i++){
		if (f[i]) continue;
		f[i] = 1; cur++;
		dfs(i, tot + sqrt((x[la]-x[i])*(x[la]-x[i]) + (y[la]-y[i])*(y[la]-y[i])));
		f[i] = 0; cur--;
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	 	cin >> x[i] >> y[i];
	dfs(0, 0.0);
	printf("%.2f", ans);
	return 0;
} 
