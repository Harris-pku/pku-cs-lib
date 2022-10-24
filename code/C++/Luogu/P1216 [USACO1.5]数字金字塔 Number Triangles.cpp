/*  Coder: Harris
    Time: 2016.8.29
    Website: https://www.luogu.com.cn/problem/P1216
    Algorithm: recurrence
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1005][1005], f[1005][1005], n;
// f[i][j] 从最下面一行走到第 i 行第 j 列能够拿到的最大值
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	 	for (int j = 1; j <= i; j++)
	  		scanf("%d", &a[i][j]);
	for (int i = n; i >= 1; i--)
	 	for (int j = 1; j <= i; j++)
	  		f[i][j] = max(f[i+1][j], f[i+1][j+1]) + a[i][j];
	printf("%d", f[1][1]);
	return 0;
}
/*
input:
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 

output:
30
*/