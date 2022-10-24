/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P2415
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, tot; long long sum;
int main(){
    while (scanf("%d", &n) == 1){
        sum += n; tot++;
    }
    sum <<= tot-1;
    cout << sum;
    return 0;
}
/*
input:
2 3

output:
10
*/