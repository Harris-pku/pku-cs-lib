/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5729
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[25][25][25], w, x, h, n, ans;
int a1, a2, b1, b2, c1, c2;
int main(){
    scanf("%d%d%d%d", &w, &x, &h, &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2);
        for (int j = a1; j <= a2; j++){
            for (int k = b1; k <= b2; k++){
                for (int l = c1; l <= c2; l++){
                    a[j][k][l] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= w; i++){
        for (int j = 1; j <= x; j++){
            for (int k = 1; k <= h; k++){
                if (!a[i][j][k]) ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
/*
input:
4 4 4
1
1 1 1 2 2 2

output:
56
*/