/*  Coder: Harris
    Time: 2015.7.16
    Website: https://www.luogu.com.cn/problem/P1423
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n = 0; double s = 0.0, k = 2.0, x;
int main(){
	scanf("%lf", &x);
	while (s <= x){
		s += k;
		k *= 0.98;
		n++;
	}
	printf("%d", n);
	return 0;
}
/*
input:
4.3

output:
3
*/