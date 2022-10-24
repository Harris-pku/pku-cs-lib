/*  Coder: Harris
    Time: 2015.10.3
    Website: https://www.luogu.com.cn/problem/P1426
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

double s, x, cur = 7.0, sum = 0.0;
int main(){
	cin >> s >> x;
	while (sum < s - x){
		sum += cur;	cur *= 0.98;
	}
	if (sum + cur <= x + s)
		printf("y");
	else
		printf("n");
	return 0;
}
/*
input:
14 1

output:
n
*/