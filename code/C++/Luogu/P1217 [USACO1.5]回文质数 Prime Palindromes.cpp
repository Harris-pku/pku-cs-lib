/*  Coder: Harris
    Time: 2015.8.30
    Website: https://www.luogu.com.cn/problem/P1217
    Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int x, y;
int huiwen(int cur){
	int p = cur, q = 0;
	while (p){
		q = q * 10 + p % 10;
		p /= 10;
	}
	if (q == cur)
		return 1;
	return 0;
}
int prime(int cur){
	for (int i = 3; i <= ceil(sqrt(cur)); i++){
		if (cur % i == 0)
			return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d", &x, &y);
	if (y >= 10000000)
		y = 10000000;
	x = (x / 2) * 2 + 1;
	for (int i = x; i <= y; i += 2){
		if (huiwen(i) && prime(i)){
			printf("%d\n", i);
		}
	}
	return 0;
}
/*
input:
5 500

output:
5
7
11
101
131
151
181
191
313
353
373
383
*/