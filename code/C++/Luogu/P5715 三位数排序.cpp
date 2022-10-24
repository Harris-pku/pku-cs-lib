/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5715
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a, b, c;
int main(){
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    printf("%d %d %d", a, b, c);
    return 0;
}
/*
input:
1 14 5

output:
1 5 14
*/