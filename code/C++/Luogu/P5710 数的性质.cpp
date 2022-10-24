/*  Coder: Harris
    Time: 2020.7.3
    Website: https://www.luogu.com.cn/problem/P5710
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool f1, f2; int x;
int main(){
    scanf("%d", &x);
    f1 = (x & 1) == 0;
    f2 = x > 4 && x <= 12;
    printf("%d ", f1 && f2 ? 1 : 0);
    printf("%d ", f1 || f2 ? 1 : 0);
    printf("%d ", f1 ^  f2 ? 1 : 0);
    printf("%d ", !f1 && !f2 ? 1 : 0);
    return 0;
}
/*
input:
12

output:
1 1 0 0
*/