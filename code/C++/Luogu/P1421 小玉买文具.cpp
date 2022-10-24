/*  Coder: Harris
    Time: 2015.7.16
    Website: https://www.luogu.com.cn/problem/P1421
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int a, b;
int main(){
	scanf("%d%d", &a, &b);
	printf("%d", (a * 10 + b) / 19);
	return 0;
}
/*
input:
10 3

output:
5
*/