/*  Coder: Harris
    Time: 2020.6.28
    Website: https://www.luogu.com.cn/problem/P1271
    Algorithm: sort with a bucket
*/
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

int a[1005], n, m, x;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d", &x);
        a[x]++;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= a[i]; j++){
            printf("%d ", i);
        }
    }
    return 0;
}
/*
input:
5 10
2 5 2 2 5 2 2 2 1 2

output:
1 2 2 2 2 2 2 2 5 5
*/