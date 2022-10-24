/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5461
    Algorithm: recurrence
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[2005][2005], n;
int main(){
    scanf("%d", &n);
    n = (1 << n); a[0][n+1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            a[i][j] = a[i-1][j] ^ a[i-1][j+1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
input:
3

output:
0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 1
0 0 0 0 0 1 0 1
0 0 0 0 1 1 1 1
0 0 0 1 0 0 0 1
0 0 1 1 0 0 1 1
0 1 0 1 0 1 0 1
1 1 1 1 1 1 1 1
*/