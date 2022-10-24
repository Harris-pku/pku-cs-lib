/*  Coder: Harris
    Time: 2020.3.8
    Website: https://www.luogu.com.cn/problem/P5706
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

double t; int n;
int main(){
    cin >> t >> n;
    printf("%.3lf\n", t / n);
    printf("%d", n * 2);
    return 0;
}
/*
input:
500.0 3

output:
166.667
6
*/