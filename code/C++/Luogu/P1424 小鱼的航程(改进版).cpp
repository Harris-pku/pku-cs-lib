/*  Coder: Harris
    Time: 2015.7.20
    Website: https://www.luogu.com.cn/problem/P1424
    Algorithm: simulation
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int x, n, ans;
int main(){
	scanf("%d%d", &x, &n);
	ans += n/7 * 5 * 250;
	n %= 7;
	for (int i = 0; i < n; i++){
		if (x+i == 6 || x+i == 7)
			continue;
		ans += 250;
	}
	printf("%d", ans);
	return 0;
}
/*
input:
3 10

output:
2000
*/