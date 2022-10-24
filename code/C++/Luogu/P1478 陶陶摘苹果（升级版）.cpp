/*  Coder: Harris
    Time: 2015.9.30
    Website: https://www.luogu.com.cn/problem/P1478
    Algorithm: greedy algorithm
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int app[5005], pri[5005], n, m, cur, x, tot, ans;
int main(){
	scanf("%d%d%d%d", &n, &m, &cur, &x);
	cur += x;
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &app[i], &pri[i]);
		if (app[i] > cur) {
			pri[i] = 0; tot++;
		}
	}
	sort(pri+1, pri+n+1);
	for (int i = tot+1; i <= n; i++){
		if (m >= pri[i]){
			m -= pri[i]; ans++;
		}
		else break;
	}
	printf("%d", ans);
	return 0;
} 
/*
input:
8 15
20 130
120 3
150 2
110 7
180 1
50 8
200 0
140 3
120 2

output:
4
*/