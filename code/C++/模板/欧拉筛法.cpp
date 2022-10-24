#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 10000005;
int prime[maxn], n, m, x, tot; bool flag[maxn];

void Euler(int n){
	memset(flag, 1, sizeof(flag));
	tot = 0; flag[0] = flag[1] = 0;
	for (int i = 2; i <= n; ++i){
		if (flag[i]) prime[++tot] = i;
	 	for (int j = 1; i*prime[j] <= n; ++j){
			flag[i*prime[j]] = 0;
	  		if (i%prime[j] == 0) break;
	 	}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	Euler(n);
	for (int i = 1; i <= m; ++i){
		scanf("%d", &x);
	 	printf(flag[x] ? "No\n" : "Yes\n");
	}
	return 0;
}
