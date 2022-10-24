/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5725
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, t;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%02d", ++t);
        }
        printf("\n");
    }
    t = 0; printf("\n");
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i+j <= n) printf("  ");
            else printf("%02d", ++t);
        }
        printf("\n");
    }
    return 0;
}
/*
input:
4

output:
01020304
05060708
09101112
13141516

      01
    0203
  040506
07080910
*/