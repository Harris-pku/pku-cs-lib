/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P2550
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int target[10], ans[10], n, tot, x;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= 7; i++){
        scanf("%d", &target[i]);
    }
    for (int i = 1; i <= n; i++){
        tot = 0;
        for (int j = 1; j <= 7; j++){
            scanf("%d", &x);
            for (int k = 1; k <= 7; k++){
                if (target[k] == x){
                    tot++; break;
                }
            }
        }
        ans[tot]++;
    }
    for (int i = 7; i > 0; i--){
        printf("%d ", ans[i]);
    }
    return 0;
}
/*
input:
2
23 31 1 14 19 17 18
12 8 9 23 1 16 7
11 7 10 21 2 9 31

output:
0 0 0 0 0 1 1
*/