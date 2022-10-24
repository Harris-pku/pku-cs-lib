/*  Coder: Harris
	Time: 2017.10.21
	Website: https://www.luogu.com.cn/problem/P1359
	Algorithm: dp
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int a[210][210], ans[210]; int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
	        scanf("%d", &a[i][j]);
        }
    }
	for (int i = 2; i <= n; i++){
		ans[i] = 10000000;
		for (int j = 1; j < i; j++){
	 	    ans[i] = min(ans[i], ans[j] + a[j][i]);
	    }
	}
	printf("%d", ans[n]);
    return 0;
}
/*
input:
3
5 15
7

output:
12
*/