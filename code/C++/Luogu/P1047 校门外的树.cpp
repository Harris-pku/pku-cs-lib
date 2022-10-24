/*  Coder: Harris
    Time: 2015.7.20
    Website: https://www.luogu.com.cn/problem/P1047
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[10005], n, m, l, r, ans = 0;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		a[i] = 1;
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &l, &r);
		for (int j = l; j <= r; j++){
			a[j] = 0; // there is no tree
		}
	}
	for (int i = 0; i <= n; i++){
		if (a[i]){ // there is a tree
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
/*
input:
500 3
150 300
100 200
470 471

output:
298
*/