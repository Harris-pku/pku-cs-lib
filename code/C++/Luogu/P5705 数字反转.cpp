/*  Coder: Harris
    Time: 2020.5.4
    Website: https://www.luogu.com.cn/problem/P5705
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

double p; int a, b, c, d, n;
int main(){
    cin >> p;
    n = int(p * 10);
    a = n / 1000;
    b = n / 100 % 10;
    c = n / 10 % 10;
    d = n % 10;
    printf("%d.%d%d%d", d, c, b, a);
    return 0;
}
/*
input:
123.4

output:
4.321
*/