/*  Coder: Harris
    Time: 2020.7.19
    Website: https://www.luogu.com.cn/problem/P3717
    Algorithm: enumeration
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int f[105][105], x, y, n, m, r, ans;
int main(){
    scanf("%d%d%d", &n, &m, &r);
    for (int k = 1; k <= m; k++){
        scanf("%d%d", &x, &y);
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (f[i][j]) continue;
                if (sqrt((x-i)*(x-i) + (y-j)*(y-j)) <= r){
                    f[i][j] = 1; ans++;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
/*
input:
5 2 1
3 3
4 2

output:
8
*/