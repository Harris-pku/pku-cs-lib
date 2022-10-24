/*  Coder: Harris
    Time: 2015.7.16
    Website: https://www.luogu.com.cn/problem/P5706
    Algorithm: simulation
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int a, b, c, d;
int main(){
	scanf("%d%d%d%d", &a, &b, &c, &d);
	c -= a;	d -= b;
	if (d < 0){
		d += 60; c -= 1;
	}
	printf("%d %d", c, d);
	return 0;
}
/*
input:
12 50 19 10

output:
6 20
*/