/*  Coder: Harris
    Time: 2016.8.10
    Website: https://www.luogu.com.cn/problem/P1176
    Algorithm: recurrence
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int f[1005][1005];
int n, m, x, y;
bool a[1005][1005];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &x, &y);
		a[x][y] = true;
	}
	f[1][1] = 1; a[1][1] = true;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (a[i][j]) continue;
			f[i][j] = (f[i-1][j] + f[i][j-1]) % 100003;
		}
	}
	printf("%d", f[n][n]);
	return 0;
}
/*
input:
3 1
3 1

output:
5
*/