/*  Coder: Harris
    Time: 2016.8.1
    Website: https://www.luogu.com.cn/problem/P1216
    Algorithm: recurrence
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[105], f[1005], n, m;
// f[i] 表示花光 i 元的总方案数
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		for (int j = m-a[i]; j >= 1; j--){
			f[j+a[i]] += f[j];
			if (j == a[i]) f[j]++;
		}
	}
	printf("%d", f[m]);
	return 0;
}
/*
input:
4 4
1 1 2 2

output:
3
*/