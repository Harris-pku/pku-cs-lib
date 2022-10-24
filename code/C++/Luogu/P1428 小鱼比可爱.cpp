/*  Coder: Harris
    Time: 2015.7.20
    Website: https://www.luogu.com.cn/problem/P1428
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[105], n, ans;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++){
		ans = 0;
		for (int j = 1; j < i; j++){
			if (a[i] > a[j]){
				ans++;
			}
		}
		printf("%d ", ans);
	}
	return 0;
}
/*
input:
6
4 3 0 5 1 2

output:
0 0 0 3 1 2
*/