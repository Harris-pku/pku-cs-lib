/*  Coder: Harris
	Time: 2016.8.2
	Website: https://www.luogu.com.cn/problem/P1010
	Algorithm: partition
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
void mi(int x){
	int t = 15, m = 0;
	for (int i = 15; i >= 0; i--){
		if (x >= (1<<i)){
			t = i; break;
		}
	}
	for (int i = t; i >= 0; i--){
		if (x <= 0) break;
	 	if (x >= (1<<i)){
		 	if (m) printf("+");
	        if (i == 1){
				printf("2"); x -= (1<<i); m = 1;
			}
	        else if (i == 0){
				printf("2(0)"); x -= (1<<i); m = 1;
			}
			else{
				printf("2(");
				x -= (1<<i); mi(i);
				m = 1; printf(")");
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	if (!n) printf("0");
	else mi(n);
	return 0;
}
