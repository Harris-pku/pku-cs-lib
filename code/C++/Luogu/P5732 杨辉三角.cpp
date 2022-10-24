/*  Coder: Harris
    Time: 2020.5.2
    Website: https://www.luogu.com.cn/problem/P5732
    Algorithm: simulation
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

int n, a[105][105];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        a[i][1] = a[i][i] = 1;
    }
    for (int i = 3; i <= n; i++){
        for (int j = 2; j < i; j++){
            a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
input:
6

output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
*/