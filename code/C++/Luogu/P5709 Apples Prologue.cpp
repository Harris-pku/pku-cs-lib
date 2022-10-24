/*  Coder: Harris
    Time: 2020.6.28
    Website: https://www.luogu.com.cn/problem/P5709
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int m, t, s;
int main(){
    scanf("%d%d%d", &m, &t, &s);
    printf("%d", max(0, m - s/t - (s%t != 0)));
    return 0;
}
/*
input:
50 10 200

output:
30
*/