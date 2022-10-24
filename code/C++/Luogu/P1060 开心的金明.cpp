/*  Coder: Harris
	Time: 2016.7.28
	Website: https://www.luogu.com.cn/problem/P1060
	Algorithm: dp
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int maxv = 30005;
int f[maxv], v[maxn], w[maxn], n, m;
int main(){
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &v[i], &w[i]);
		w[i] *= v[i];
		for (int j = m; j >= v[i]; j--){
			f[j] = max(f[j], f[j-v[i]] + w[i]);
		}
	}
	printf("%d", f[m]);
	return 0;
}
/*
input:
1000 5
800 2
400 5
300 5
400 3
200 2

output:
3900
*/