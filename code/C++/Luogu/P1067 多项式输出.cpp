/*  Coder: Harris
    Time: 2016.8.4
    Website: https://www.luogu.com.cn/problem/P1067
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, a;
int main(){
	scanf("%d", &n);
	for (int i = n; i > 0; i--){
		scanf("%d", &a);
	 	if (!a) continue;
	 	if (a > 0){
		 	if (i != n) printf("+");
			if (a != 1) printf("%d", a);
	    } 
	 	if (a < 0){
		 	if (a != -1) printf("%d", a);
	        else printf("-");
	 	}
		if (i != 1) printf("x^%d", i);
		else printf("x");
	}
	scanf("%d", &a);
	if (a>0 && n) printf("+%d", a);
	if (a < 0) printf("%d", a);
	if (a>=0 && n==0) printf("%d", a);
	return 0;
}
/*
input:
5 
100 -1 1 -3 0 10

output:
100x^5-x^4+x^3-3x^2+10
*/