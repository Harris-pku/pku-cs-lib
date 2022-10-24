/*  Coder: Harris
    Time: 2020.5.2
    Website: https://www.luogu.com.cn/problem/P5731
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[15][15], n, k = 1, x = 1, y = 0;
int main(){
    scanf("%d", &n);
    while (k <= n*n){
        while (y<n && !a[x][y+1]) a[x][++y] = k++;
        while (x<n && !a[x+1][y]) a[++x][y] = k++;
        while (y>1 && !a[x][y-1]) a[x][--y] = k++;
        while (x>1 && !a[x-1][y]) a[--x][y] = k++;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
input:
4

output:
  1  2  3  4
 12 13 14  5
 11 16 15  6
 10  9  8  7
*/