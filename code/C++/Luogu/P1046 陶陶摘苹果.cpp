/*  Coder: Harris
    Time: 2015.7.20
    Website: https://www.luogu.com.cn/problem/P1046
    Algorithm: simulation
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int a[15], t, ans;
int main(){
	for (int i = 1; i <= 10; i++)
		scanf("%d", &a[i]);
	scanf("%d", &t);
	for (int i = 1; i <= 10; i++){
		if (t + 30 >= a[i]){
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
/*
input:
100 200 150 140 129 134 167 198 200 111
110

output:
5
*/