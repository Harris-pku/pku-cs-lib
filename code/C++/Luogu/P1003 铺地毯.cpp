/*  Coder: Harris
	Time: 2015.7.26
	Website: https://www.luogu.com.cn/problem/P1003
	Algorithm: enumeration
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int x[10005], y[10005], a[10005], b[10005];
int n, xx, yy, k = -1;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d%d%d%d", &x[i], &y[i], &a[i], &b[i]);
	}
	scanf("%d%d", &xx, &yy);
	for (int i = n; i >= 1; i--){
		if (x[i]<=xx && xx<=x[i]+a[i] && y[i]<=yy && yy<=y[i]+b[i]){
			k = i; break;
		}
	}
	printf("%d", k);
	return 0;
}
/*
input:
3
1 0 2 3
0 2 3 3
2 1 3 3
2 2

output:
3
*/