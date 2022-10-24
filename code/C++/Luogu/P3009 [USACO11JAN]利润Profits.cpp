#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int m, ans = -10000, maxn, n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &m);
		if (maxn > 0)
			maxn += m;
		else
			maxn = m;
		ans = max(ans, maxn);
	}
	printf("%d", ans);
	return 0;
}
