/*  Coder: Harris
    Time: 2015.7.20
    Website: https://www.luogu.com.cn/problem/P1427
    Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int a[105], tot, n;
int main(){
	while (scanf("%d", &n) == 1 && n){
		a[++tot] = n;
	}
	for (int i = tot; i >= 1; i--){
		printf("%d ", a[i]);
	}
	return 0;
}
/*
input:
3 65 23 5 34 1 30 0

output:
30 1 34 5 23 65 3
*/