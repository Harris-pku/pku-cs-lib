/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5722
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int sum, n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        sum += i;
    }
    printf("%d", sum);
    return 0;
}
/*
input:
100

output:
5050
*/