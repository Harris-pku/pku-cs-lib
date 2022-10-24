/*  Coder: Harris
    Time: 2015.9.26
    Website: https://www.luogu.com.cn/problem/P1328
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int h[30] = {0, -1, 1, 1, -1, 1, 0, -1, 1, -1, -1, 1, 0, -1, 1, -1, -1, 1, 0, 1, 1, 1, -1, -1, 0};
int a[205], b[205], f[5][5], n, na, nb, ansx, ansy;
int main(){
	scanf("%d%d%d", &n, &na, &nb);
	for (int i = 0; i < na; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < nb; i++){
		scanf("%d", &b[i]);
	}
	for (int i = 0; i <= 4; i++){
		for (int j = 0; j <= 4; j++){
			f[i][j] = h[i*5 + j];
		}
	}
	for (int i = 0; i < n; i++){
		if (f[a[i % na]][b[i % nb]] == 1)
			ansx++;
		else if (f[a[i % na]][b[i % nb]] == -1)
			ansy++;
	}
	printf("%d %d", ansx, ansy);
	return 0;
}
/*
input:
10 5 6
0 1 2 3 4
0 3 4 2 1 0

output:
6 2
*/