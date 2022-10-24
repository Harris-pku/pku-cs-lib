/*  Coder: Harris
    Time: 2015.7.16
    Website: https://www.luogu.com.cn/problem/P1035
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int k, n; double s = 0.0;
int main(){
	scanf("%d", &k);
	while (s <= k){
		n++;
		s += (1.0) / (n * 1.0);
	}
	printf("%d", n);
	return 0;
}
/*
input:
1

output:
2
*/