/*  Coder: Harris
    Time: 2020.7.3
    Website: https://www.luogu.com.cn/problem/P5723
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100005;
int prime[maxn], m, tot; bool flag[maxn];

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
	scanf("%d", &m);
	Euler(maxn);
	for (int i = 1; i <= tot; i++){
		m -= prime[i];
        if (m >= 0){
            printf("%d\n", prime[i]);
        }
        else{
            printf("%d", i-1); break;
        }
	}
	return 0;
}
/*
input:
100

output:
2
3
5
7
11
13
17
19
23
9
*/