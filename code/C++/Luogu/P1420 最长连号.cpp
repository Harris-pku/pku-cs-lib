/*  Coder: Harris
    Time: 2016.8.3
    Website: https://www.luogu.com.cn/problem/P1420
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, m, t, maxx = 1, ans;
int main(){
	scanf("%d%d", &n, &t);
	for (int i = 2; i <= n; i++){
		scanf("%d", &m);
		if (m == t + 1)
			maxx++;
		else
			maxx = 1;
		ans = max(ans, maxx);
		t = m;
	}
	printf("%d", ans);
	return 0;
}
/*
input:
10
3 5 6 2 3 4 5 6 8 9

output:
5
*/