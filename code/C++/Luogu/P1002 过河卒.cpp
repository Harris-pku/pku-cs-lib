/*  Coder: Harris
	Time: 2015.8.24
	Website: https://www.luogu.com.cn/problem/P1002
	Description: there is a knight in a chess board,
				 given the coordinate of the knight,
				 how many routes from (0, 0) to (n, m)
	Algorithm: recurrence
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int hx[10] = {0, 1, 1, 2, 2, -1, -1, -2, -2};
int hy[10] = {0, 2, -2, -1, 1, 2, -2, 1, -1};
long long ans[25][25]; int f[25][25], n, m, x, y;
int main(){
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i < 9; i++){
		int xx = x + hx[i], yy = y + hy[i];
		if (xx<0 || xx>n || yy<0 || yy>m) continue;
		f[xx][yy] = 1;
	}
	for (int i = 0; i <= n; ++i){
		if (f[i][0]) break;
		ans[i][0] = 1;
	}
	for (int j = 0; j <= m; ++j){
		if (f[0][j]) break;
		ans[0][j] = 1;
	}
	for (int i = 1; i <= n; ++i){
	 	for (int j = 1; j <= m; ++j){
	 		if (f[i][j]) continue;
	 		ans[i][j] = ans[i-1][j] + ans[i][j-1];
	 	}
	}
	cout << ans[n][m];
	return 0;
} 
/*
input:
6 6 3 3

output:
6
*/