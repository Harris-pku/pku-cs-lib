/*  Coder: Harris
    Time: 2016.9.18
    Website: https://www.luogu.com.cn/problem/P1789
    Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int o[115][115], z, n, m, k, x, y;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n + 4; i++)
		for (int j = 0; j <= n + 4; j++)
			o[i][j] = 1;
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &x, &y);
		o[x+2][y+2] = o[x+1][y+2] = 0;
		o[x][y+2] = o[x+3][y+2] = 0;
		o[x+4][y+2] = o[x+2][y] = 0;
		o[x+2][y+1] = o[x+2][y+3] = 0;
		o[x+2][y+4] = o[x+1][y+1] = 0;
		o[x+1][y+3] = o[x+3][y+1] = 0;
		o[x+3][y+3] = 0;
	}
	for (int i = 1; i <= k; i++){
		scanf("%d%d", &x, &y);
		for (int q = 1; q <= 5; q++)
			for (int w = 1; w <= 5; w++)
				o[x+q-1][y+w-1] = 0;
	}
	for (int i = 3; i <= n + 2; i++){
		for (int j = 3; j <= n + 2; j++)
			if (o[i][j]) z++;
	}
	printf("%d", z);
	return 0;
}
/*
input:
5 1 0
3 3

output:
12
*/