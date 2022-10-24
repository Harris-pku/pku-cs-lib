/*  Coder: Harris
    Time: 2020.7.8
    Website: https://www.luogu.com.cn/problem/P5712
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int x;
int main(){
    scanf("%d", &x);
    printf("Today, I ate %d apple", x);
    if (x > 1) printf("s");
    printf(".");
    return 0;
}
/*
input:
3

output:
Today, I ate 3 apples.
*/