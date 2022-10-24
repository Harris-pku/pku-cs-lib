#include <cstdio>
#include <algorithm>

using namespace std;

int a[20];
int n, m, ans = 0x7fffffff;
void dfs(int t, int h){
	if (t > n)
		return;
	if (t == n && h >= m)
		ans = min(ans, h - m);
	dfs(t+1, h+a[t]);
	dfs(t+1, h);
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}
