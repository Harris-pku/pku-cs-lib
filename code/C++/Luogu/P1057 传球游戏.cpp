/*  Coder: Harris
    Time: 2015.9.26
    Website: https://www.luogu.com.cn/problem/P1057
    Algorithm: recurrence
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

int f[35][35], n, m;
// f[i][j] 代表 传了 i 次后球在 j 手中的总方案数
int main(){
    scanf("%d%d", &n, &m); f[0][1] = 1;
    for (int k = 1; k <= m; k++){
        f[k][1] = f[k-1][2] + f[k-1][n];
        for (int i = 2; i < n; i++)
            f[k][i] = f[k-1][i-1] + f[k-1][i+1];
        f[k][n] = f[k-1][n-1] + f[k-1][1];
    }
    printf("%d", f[m][1]);
    return 0;
}
/*
input:
3 3

output:
2
*/