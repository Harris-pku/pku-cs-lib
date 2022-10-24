/*  Coder: Harris
    Time: 2020.4.30
    Website: https://www.luogu.com.cn/problem/P5711
    Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int x;
int main(){
	cin >> x;
	if ((x%4==0 && x%100!=0) || x%400==0) cout << 1;
	else cout << 0;
	return 0;
}
/*
input:
2000

output:
1
*/