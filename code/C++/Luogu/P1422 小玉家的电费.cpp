/*  Coder: Harris
    Time: 2015.7.16
    Website: https://www.luogu.com.cn/problem/P1422
    Algorithm: simulation
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n; double ans;
int main(){
	scanf("%d", &n);
	if (n <= 150)
		ans = n * 0.4463;
	else if (n > 150 && n <= 400)
		ans = (n - 150) * 0.4663 + 150 * 0.4463;
	else
		ans = (n - 400) * 0.5663 + 150 * 0.4463 + 250 * 0.4663;
	printf("%.1lf\n", ans);
	return 0;
}
/*
input:
267

output:
121.5
*/