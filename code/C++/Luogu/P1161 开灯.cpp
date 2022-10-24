/*  Coder: Harris
    Time: 2016.8.21
    Website: https://www.luogu.com.cn/problem/P1161
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int n, t, ans; double a;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lf %d", &a, &t);
        for (int j = 1; j <= t; j++){
            int x = floor(a * j);
            ans ^= x;
        }
    }
    printf("%d", ans);
    return 0;
}
/*
input:
3
1.618034 13
2.618034 7
1.000000 21

output:
20
*/