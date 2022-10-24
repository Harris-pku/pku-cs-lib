/*  Coder: Harris
    Time: 2016.8.5
    Website: https://www.luogu.com.cn/problem/P2676
    Algorithm: greedy algorithm
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[20005];
int n, sum, t, ans;
int cmp(int a, int b){
	return a > b;
}
int main(){
	scanf("%d%d", &n, &sum);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n, cmp);
	for (int i = 0; i < n; i++){
		t += a[i]; ans++;
		if (t >= sum){
			break;
		}
	}
	printf("%d", ans);
	return 0;
}
/*
input:
6 40
6
18
11
13
19
11

output:
3
*/