/*  Coder: Harris
	Time: 2016.8.3
	Website: https://www.luogu.com.cn/problem/P1006
	Algorithm: dp
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int h[5][2] = {0, 0, 0, 0, 0, -1, -1, 0, -1, -1};
int f[105][55][55], a[55][55], n, m;
int main(){
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i)
	 	for (int j = 1; j <= n; ++j)
	  		scanf("%d", &a[i][j]);
	f[1][1][2] = a[1][2] + a[2][1];
	for (int i = 2; i < n+m-2; ++i){
	 	for (int j = 1; j <= i+1; ++j){
	   		if (i+2-j > m) continue;
	   		for (int k = 1; k <= i+1; ++k){
	    		if (j>=k || i+2-k>m) continue;
	    		for (int t = 1; t <= 4; ++t){
	    			f[i][j][k] = max(f[i][j][k], f[i-1][j+h[t][0]][k+h[t][1]] + a[i+2-j][j] + a[i+2-k][k]);
	    		}
	   		}
	 	}
	}
	printf("%d", f[n+m-3][n-1][n]);
	return 0;
}
/*
input:
3 3
0 3 9
2 8 5
5 7 0

output:
34
*/