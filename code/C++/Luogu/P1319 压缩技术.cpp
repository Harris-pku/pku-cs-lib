/*  Coder: Harris
	Time: 2016.8.5
	Website: https://www.luogu.com.cn/problem/P1319
	Algorithm: simulation
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, t, m, h;
int main(){
	scanf("%d", &n);
	while (scanf("%d", &t) == 1){
		for (int i = 1; i <= t; i++){
			m++;
			if (m % n)
				printf("%d", h);
			else
				printf("%d\n", h);
		}
		h++; h &= 1;
	}
	return 0;
}
/*
input:
7 3 1 6 1 6 4 3 1 6 1 6 1 3 7

output:
0001000
0001000
0001111
0001000
0001000
0001000
1111111
*/