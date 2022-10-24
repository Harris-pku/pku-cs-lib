/*  Coder: Harris
    Time: 2020.7.8
    Website: https://www.luogu.com.cn/problem/P5724
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, x, maxn, minn = 0x3f3f3f3f;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        maxn = max(maxn, x);
        minn = min(minn, x);
    }
    printf("%d", maxn - minn);
    return 0;
}
/*
input:
6
1 1 4 5 1 4

output:
4
*/