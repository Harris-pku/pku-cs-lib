/*  Coder: Harris
    Time: 2015.11.21
    Website: https://www.luogu.com.cn/problem/P2615
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[50][50], n, x, y;
int main(){
    scanf("%d", &n);
    int x = 1, y = (n+1) / 2;
    for (int i = 1; i <= n*n; i++){
        a[x][y] = i;
        int xx = x-1, yy = y+1;
        if (xx < 1) xx += n;
        if (yy > n) yy -= n;
        if (a[xx][yy]){
            xx = x+1; yy = y;
            if (xx > n) xx -= n;
        }
        x = xx; y = yy;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
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
8 1 6
3 5 7
4 9 2
*/