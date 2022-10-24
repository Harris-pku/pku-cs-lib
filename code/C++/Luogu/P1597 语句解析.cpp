/*  Coder: Harris
    Time: 2016.8.6
    Website: https://www.luogu.com.cn/problem/P1597
    Algorithm: simulation
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[5]; char s1, s2;
int main(){
	while (scanf("%c:=%c;", &s1, &s2) == 2){
		a[s1 - 'a'] = (s2 >= '0' && s2 <= '9') ? s2 - '0' : a[s2 - 'a'];
	}
	printf("%d %d %d", a[0], a[1], a[2]);
	return 0;
}
/*
input:
a:=3;b:=4;c:=5;

output:
3 4 5
*/