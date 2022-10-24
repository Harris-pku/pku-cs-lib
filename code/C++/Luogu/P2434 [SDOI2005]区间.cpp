#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[1000010], n, m, x, y, t, maxn, minn = 1000010;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	{
		scanf("%d%d", &x, &y);
		a[x]++; a[y]--;
		maxn = max(maxn, y + 2);
		minn = min(minn, x);
	}
	for (int i = max(1, minn - 2); i <= maxn; i++){
		a[i] += a[i - 1];
		if (a[i] && !a[i - 1])
			printf("%d ", i);
		if (!a[i] && a[i - 1])
			printf("%d\n", i);
	}
	return 0;
}
