/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P3156
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[2000005], n, m, x;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++){
        scanf("%d", &x);
        printf("%d\n", a[x]);
    }
    return 0;
}
/*
input:
10 3
1 9 2 60 8 17 11 4 5 14
1 5 9

output:
1
8
5
*/