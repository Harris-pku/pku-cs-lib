/*  Coder: Harris
    Time: 2015.8.28
    Website: https://www.luogu.com.cn/problem/P1177
    Algorithm: simulation
*/
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

int a[100005], n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
/*
input:
5
4 2 4 5 1

output:
1 2 4 4 5
*/