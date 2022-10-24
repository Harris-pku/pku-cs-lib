/*  Coder: Harris
    Time: 2016.8.5
    Website: https://www.luogu.com.cn/problem/P1125
    Algorithm: simulation
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

char s[110]; int a[30], len, maxn, minn = 100;
int is_prime(int n){
	if (n <= 1)
		return 0;
	int m = floor(sqrt(n));
	for (int i = 2; i <= m; i++)
		if (!n % m)
			return 0;
	return 1;
}
int main(){
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i < len; i++){
		a[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++){
		if (!a[i])
			continue;
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
	}
	if (is_prime(maxn - minn))
		printf("Lucky Word\n%d", maxn - minn);
	else
		printf("No Answer\n0");
	return 0;
}
/*
input:
error

output:
Lucky Word
2
*/