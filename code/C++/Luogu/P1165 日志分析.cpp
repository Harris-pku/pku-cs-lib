/*  Coder: Harris
    Time: 2016.7.29
    Website: https://www.luogu.com.cn/problem/P1165
    Algorithm: stack
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[200005], top, maxn, n, k;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &k);
	 	if (!k){
		 	scanf("%d", &a[++top]); // push
	        maxn = a[top] = max(maxn, a[top]);
		}
	 	if (k == 1) if (top) maxn = a[--top];
	 	if (k == 2) printf("%d\n", maxn);
	}
	return 0;
} 
/*
input:
13
0 1
0 2
2
0 4
0 2
2
1
2
1
1
2
1
2

output:
2
4
4
1
0
*/