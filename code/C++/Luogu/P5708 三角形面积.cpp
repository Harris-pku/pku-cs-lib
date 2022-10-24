/*  Coder: Harris
    Time: 2020.4.30
    Website: https://www.luogu.com.cn/problem/P5708
    Algorithm: simulation
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	double a, b, c, p, s;
	cin >> a >> b >> c;
	p = (a+b+c) / 2;
	s = sqrt(p * (p-a) * (p-b) * (p-c));
    printf("%.1lf", s);
	return 0;
}
/*
input:
3 4 5

output:
6.0
*/