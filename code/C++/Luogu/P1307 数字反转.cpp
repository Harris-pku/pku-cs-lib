/*  Coder: Harris
    Time: 2015.7.16
    Website: https://www.luogu.com.cn/problem/P1307
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, cur, ans;
int main(){
	scanf("%d", &n);
	if (n < 0){
		printf("-");
		n *= -1;
	}
	while (n){
		cur = n % 10;
		ans = ans * 10 + cur;
		n /= 10;
	}
	printf("%d", ans);
	return 0;
}
/*
input:
123

output:
321
*/