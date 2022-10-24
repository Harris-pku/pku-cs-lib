/*  Coder: Harris
    Time: 2020.1.30
    Website: https://www.luogu.com.cn/problem/P1209
    Algorithm: greedy
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[205], f[205], m, s, c, ans;
int cmp(int x, int y){
	return x > y;
}
int main(){
	scanf("%d%d%d", &m, &s, &c);
	for (int i = 1; i <= c; i++){
		scanf("%d", &a[i]);
	}
	if (m > c){
		printf("%d", c); return 0;
	}
	sort(a+1, a+c+1);
	ans = a[c] - a[1] + 1;
	for (int i = 2; i <= c; i++){
		f[i-1] = a[i] - a[i-1];
	}
	sort(f+1, f+c, cmp);
	for (int i = 1; i <= m-1; i++){
		ans = ans - f[i] + 1;
	}
	printf("%d", ans);
	return 0;
}
/*
input:
4 50 18
3 
4 
6 
8 
14
15 
16 
17 
21
25 
26 
27 
30 
31 
40 
41 
42 
43

output:
25
*/