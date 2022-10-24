/*  Coder: Harris
    Time: 2016.8.7
    Website: https://www.luogu.com.cn/problem/P1152
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[1005], n, h, t, j;
int main(){
	scanf("%d%d", &n, &h);
	for (int i = 1; i < n; i++){
		scanf("%d", &t);
		a[abs(h-t)]++;
		h = t;
	}
	for (int i = 1; i < n; i++)
		if (!a[i]){
			printf("Not jolly");
			j = 1; break;
		}
	if (!j)
		printf("Jolly");
	return 0;
}
/*
input:
4 1 4 2 3

output:
Jolly
*/