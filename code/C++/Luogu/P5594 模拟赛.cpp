/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5594
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[1005][1005], n, m, k, x;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%d", &x);
            a[x][j] = 1;
        }
    }
    for (int i = 1; i <= k; i++){
        int sum = 0;
        for (int j = 1; j <= m; j++){
            sum += a[i][j];
        }
        printf("%d ", sum);
    }
    return 0;
}
/*
input:
6 3 7
2 3 4
2 5 7
3 5 7
1 3 5
5 6 7
1 2 3

output:
1 2 3 1 3 1 1
*/