/*  Coder: Harris
    Time: 2018.11.18
    Website: https://www.luogu.com.cn/problem/P5015
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char s[20]; int ans;
int main(){
	while (cin >> s){
		ans += strlen(s);
	}
	printf("%d", ans);
	return 0;
}
/*
input:
Ca 45 

output:
4
*/