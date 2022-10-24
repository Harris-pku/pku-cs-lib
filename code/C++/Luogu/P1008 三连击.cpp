/*  Coder: Harris
	Time: 2015.7.20
	Website: https://www.luogu.com.cn/problem/P1008
	Algorithm: enumeration
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int f[15], tot;
void solve(int x){
	f[x/100] = f[x/10%10] = f[x%10] = 1;
}
int main(){
	for (int i = 100; i <= 333; i++){
		memset(f, 0, sizeof(f));
		tot = 0;
		solve(i); solve(i*2); solve(i*3);
		for (int j = 1; j <= 9; j++){
			if (f[j]) tot++;
		}
		if (tot == 9){
			printf("%d %d %d\n", i, 2*i, 3*i);
		}
	}
	return 0;
}
/*
output:
192 384 576
219 438 657
273 546 819
327 654 981
*/