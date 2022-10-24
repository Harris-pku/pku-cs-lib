#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int v[5010], w[5010], f[20010], n, m;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &v[i], &w[i]);
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d", f[m]);
	return 0;
}
