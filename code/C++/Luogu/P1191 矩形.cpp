#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <iostream>

using namespace std;

char s; int n, m, k, ans, f[155][155];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			cin >> s;
			if (s == 'W')
				f[i][j] = f[i][j - 1] + 1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			if (!f[i][j])
				continue;
			k = i;
			m = f[i][j];
			while (k >= 1 && m > 0){
				m = min(m, f[k][j]);
				ans += m;
				k--;
			}
		}
	printf("%d", ans);
	return 0;
}
