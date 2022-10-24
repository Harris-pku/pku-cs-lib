/*  Coder: Harris
	Time: 2016.8.3
	Website: https://www.luogu.com.cn/problem/P1004
	Algorithm: dp
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int h[5][2] = {0, 0, 0, 0, 0, -1, -1, 0, -1, -1};
int f[105][55][55], a[55][55], n, x, y;
int main(){
	scanf("%d", &n);
	while (scanf("%d%d", &x, &y) == 2 && x && y)
	 	scanf("%d", &a[x][y]);
	f[1][1][2] = a[1][2] + a[2][1] + a[1][1];
	for (int i = 2; i < n*2-2; i++){
	 	for (int j = 1; j <= i+1; j++){
	   		if (i+2-j > n) continue;
	   	 	for (int k = 1; k <= i + 1; ++k){
	    	 	if (j >= k || i+2-k > n) continue;
	    	 	for (int t = 1; t <= 4; ++t){
				 	f[i][j][k] = max(f[i][j][k], f[i-1][j+h[t][0]][k+h[t][1]] + a[i+2-j][j] + a[i+2-k][k]);
	    	 	}
	   	 	}
	  	}
	}
	f[n*2-2][n][n] = f[n*2-3][n-1][n] + a[n][n];
	printf("%d", f[n*2-2][n][n]);
	return 0;
}
/*
input:
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0

output:
67
*/