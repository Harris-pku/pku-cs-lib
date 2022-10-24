/*  Coder: Harris
    Time: 2016.8.21
    Website: https://www.luogu.com.cn/problem/P1554
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[10], l, r;
void sum(int x){
	while (x){
		a[x % 10]++;
		x /= 10;
	}
}

int main(){
	scanf("%d%d", &l, &r);
	for (int i = l; i <= r; i++)
		sum(i);
	for (int i = 0; i <= 9; i++)
		printf("%d ", a[i]);
	return 0;
}
/*
input:
129 137

output:
1 10 2 9 1 1 1 1 0 1
*/