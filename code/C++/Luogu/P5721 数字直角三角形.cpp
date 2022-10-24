/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5721
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, t = 1;
int main(){
    scanf("%d", &n);
    for (int i = n; i >= 1; i--){
        for (int j = 1; j <= i; j++){
            printf("%02d", t++);
        }
        printf("\n");
    }
    return 0;
}
/*
input:
5

output:
0102030405
06070809
101112
1314
15
*/