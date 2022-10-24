/*  Coder: Harris
    Time: 2020.5.2
    Website: https://www.luogu.com.cn/problem/P5739
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int fac(int n){
    if (n <= 1) return 1;
    return fac(n-1) * n;
}

int n;
int main(){
    scanf("%d", &n);
    printf("%d", fac(n));
    return 0;
}
/*
input:
3

output:
6
*/