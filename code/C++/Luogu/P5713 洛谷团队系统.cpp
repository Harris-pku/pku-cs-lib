/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5713
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
    if (x > 5) printf("Luogu");
    else printf("Local");
    return 0;
}
/*
input:
50

output:
Luogu
*/