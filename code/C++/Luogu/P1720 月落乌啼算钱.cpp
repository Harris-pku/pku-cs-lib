/*  Coder: Harris
    Time: 2018.7.30
    Website: https://www.luogu.com.cn/problem/P1720
    Algorithm: simulation
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long a[55] = {0, 1, 1}, n;
int main(){
	cin >> n;
	for (int i = 3; i <= n; i++)
		a[i] = a[i - 1] + a[i - 2];
	printf("%.2lf", a[n] * 1.0);
	return 0;
}
/*
input:
6

output:
8.00
*/