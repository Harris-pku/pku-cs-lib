/*  Coder: Harris
    Time: 2015.10.1
    Website: https://www.luogu.com.cn/problem/P2089
    Algorithm: dfs
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[10005][13], cur[15], n, ans, sum;
void dfs(int x){
	if (x == 11){
		if (sum == n){
			ans++;
			for (int i = 1; i <= 10; i++){
				a[ans][i] = cur[i];
			}
		}
		return;
	}
	if (sum > n)
		return;
	for (int i = 1; i <= 3; i++){
		sum += i; cur[x] = i;
		dfs(x + 1);
		sum -= i; cur[x] = 0;
	}
}
int main(){
	scanf("%d", &n);
	dfs(1);
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++){
		for (int j = 1; j <= 10; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
input:
11

output:
10
1 1 1 1 1 1 1 1 1 2 
1 1 1 1 1 1 1 1 2 1 
1 1 1 1 1 1 1 2 1 1 
1 1 1 1 1 1 2 1 1 1 
1 1 1 1 1 2 1 1 1 1 
1 1 1 1 2 1 1 1 1 1 
1 1 1 2 1 1 1 1 1 1 
1 1 2 1 1 1 1 1 1 1 
1 2 1 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 1 1 
*/