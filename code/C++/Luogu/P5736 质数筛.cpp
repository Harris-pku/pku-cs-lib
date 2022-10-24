/*  Coder: Harris
    Time: 2020.5.2
    Website: https://www.luogu.com.cn/problem/P5736
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

bool is_prime(int n){
    if (n < 2) return false;
    int m = floor(sqrt(n));
    for (int i = 2; i <= m; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int a[105], n, tot, x;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        if (is_prime(x)){
            a[++tot] = x;
        }
    }
    for (int i = 1; i <= tot; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
/*
input:
5
3 4 5 6 7

output:
3 5 7
*/