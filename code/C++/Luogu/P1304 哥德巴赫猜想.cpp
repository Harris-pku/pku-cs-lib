/*  Coder: Harris
    Time: 2015.10.4
    Website: https://www.luogu.com.cn/problem/P1304
    Algorithm: simulation
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int flag1, flag2, n;
int main(){
    scanf("%d", &n);
    for (int k = 4; k <= n; k += 2){
        for (int i = 2; i <= k / 2; i++){
            flag1 = 1;
            for (int j = 2; j <= floor(sqrt(i)); j++){
                if (i % j == 0){
                    flag1 = 0; break;
                }
            }
            if (flag1){
                flag2 = 1;
                for (int j = 2; j <= floor(sqrt(k-i)); j++){
                    if ((k-i) % j == 0){
                        flag2 = 0; break;
                    }
                }
                if (flag2){
                    printf("%d=%d+%d\n", k, i, k - i); break;
                }
            }
        }
    }
    return 0;
}
/*
input:
10

output:
4=2+2
6=3+3
8=3+5
10=3+7
*/