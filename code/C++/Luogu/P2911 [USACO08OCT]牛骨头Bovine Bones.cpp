/*  Coder: Harris
    Time: 2018.7.30
    Website: https://www.luogu.com.cn/problem/P2911
    Algorithm: simulation
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[105], n, m, p, ans, maxn;
int main(){
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; ++i)
	 	for (int j = 1; j <= m; ++j)
	  		for (int k = 1; k <= p; ++k)
	   			a[i+j+k]++;
	for (int i = 1; i <= n+m+p; ++i)
	 	if (a[i] > maxn){
			maxn = a[i]; ans = i;
		}
	printf("%d", ans);
	return 0;
}
/*
input:
3 2 3 

output:
5
*/