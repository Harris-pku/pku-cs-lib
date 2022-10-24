/*  Coder: Harris
    Time: 2017.2.18
    Website: https://www.luogu.com.cn/problem/P1909
    Algorithm: simulation
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n, num, price, cur, minn = 0x7fffffff;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= 3; i++){
		scanf("%d%d", &num, &price);
		cur = (n / num) * price;
		if (n % num)
			cur += price;
		minn = min(minn, cur);
	}
	printf("%d", minn);
	return 0;
}
/*
input:
9998
128 233
128 2333
128 666

output:
18407
*/