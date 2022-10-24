/*  Coder: Harris
    Time: 2015.7.20
    Website: https://www.luogu.com.cn/problem/P1980
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, x, cur, ans = 0;
int main(){
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++){
		cur = i;
		while (cur){
			if (x == cur % 10)
				ans++;
			cur /= 10;
		}
	}
	printf("%d", ans);
	return 0;
}
/*
input:
11 1

output
4
*/