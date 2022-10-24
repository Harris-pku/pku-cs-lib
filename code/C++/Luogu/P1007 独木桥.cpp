/*  Coder: Harris
	Time: 2015.11.5
	Website: https://www.luogu.com.cn/problem/P1007
	Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int l, n, minn, maxn, cur;
int main(){
	scanf("%d%d", &l, &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &cur);
		minn = max(minn, min(cur, l+1-cur));
		maxn = max(maxn, max(cur, l+1-cur));
	}
	printf("%d %d", minn, maxn);
	return 0;
}
/*
input:
4
2
1 3

output:
2 4
*/