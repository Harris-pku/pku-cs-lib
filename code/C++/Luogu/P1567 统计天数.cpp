#include <cstdio>
#include <algorithm>

using namespace std;

int n, cur, bef, maxn = 1, ans;
int main(){
	scanf("%d%d", &n, &bef);
	for (int i = 2; i <= n; i++){
		scanf("%d", &cur);
		if (cur > bef)
			maxn++;
		else
			maxn = 1;
		ans = max(ans, maxn);
		bef = cur;
	}
	printf("%d", ans);
	return 0;
}
