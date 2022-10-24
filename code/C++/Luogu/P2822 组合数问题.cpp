#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int c[2010][2010], s[2010][2010];
int n[10010], m[10010];
int maxn, maxm, mmax, t, k;
int main(){
	scanf("%d%d", &t, &k);
	for (int i = 1; i <= t; i++){
		scanf("%d%d", &n[i], &m[i]);
		maxn = max(maxn, n[i]);
		maxm = max(maxm, m[i]);
	}
	mmax = max(maxn, maxm);
	for (int i = 1; i <= mmax; i++)
		c[i][i] = c[i][0] = 1;
	for (int i = 2; i <= mmax; i++)
		for (int j = 1; j <= mmax; j++){
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % k;
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (j<=i && c[i][j]==0);
		}
	for (int i = 1; i <= t; i++)
		printf("%d\n", s[n[i]][m[i]]);
	return 0;
}
