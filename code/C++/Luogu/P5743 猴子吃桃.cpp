/*  Coder: Harris
    Time: 2020.5.4
    Website: https://www.luogu.com.cn/problem/P5743
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int f(int n){
    if (n == 1) return 1;
    return 2*(f(n-1) + 1); // f(n) = 2(f(n-1) + 1)
}

int n;
int main(){
    scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}
/*
input:
4

output:
22
*/