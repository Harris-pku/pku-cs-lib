#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int c[105][105], n;
int main(){
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i){
        c[i][0] = c[i][i] = 1;
    }
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= i; ++j){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}