#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int dat[60][1010], n, x, f, maxn;
int main(){
	scanf("%d%d%d", &n, &x, &maxn);
	dat[0][x] = 1;
	for (int i = 1; i <= n; i++){
		f = 0; scanf("%d", &x);
		for (int j = 0; j <= maxn; j++)
			if (dat[i - 1][j]){
				if (j + x <= maxn || j - x >= 0)
					f = 1;
				if (j + x <= maxn)
					dat[i][j + x] = 1;
				if (j - x >= 0)
					dat[i][j - x] = 1;
			}
		if (!f){
			printf("-1"); break;
		}
	}
	for (int i = maxn; i >= 0; i--)
		if (dat[n][i]){
			printf("%d\n", i); break;
		}
	return 0;
}
