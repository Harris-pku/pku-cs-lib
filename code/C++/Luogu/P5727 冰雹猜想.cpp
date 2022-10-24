/*  Coder: Harris
    Time: 2020.7.8
    Website: https://www.luogu.com.cn/problem/P5727
    Algorithm: recurrence
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;

void solve(int x){
    if (x == 1) printf("1 ");
    if (x <= 1) return;
    if (x & 1) solve(3*x + 1);
    else solve(x / 2);
    printf("%d ", x);
}

int main(){
    scanf("%d", &n);
    solve(n);
    return 0;
}
/*
input:
20

output:
1 2 4 8 16 5 10 20
*/