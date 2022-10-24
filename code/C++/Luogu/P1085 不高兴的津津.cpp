/*  Coder: Harris
    Time: 2015.7.16
    Website: https://www.luogu.com.cn/problem/P1085
    Algorithm: simulation
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int x, y, flag, maxx, ans;
int main(){
	for (int i = 1; i <= 7; i++){
		scanf("%d%d", &x, &y);
		if (x + y > 8){
			flag = 1;
			if (x + y > maxx){
				maxx = x + y;
				ans = i;
			}
		}
	}
	if (!flag)
		printf("0");
	else
		printf("%d", ans);
	return 0;
}
/*
input:
5 3
6 2
7 2
5 3
5 4
0 4
0 6

output:
3
*/