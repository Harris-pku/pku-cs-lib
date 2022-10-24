/*  Coder: Harris
    Time: 2020.7.8
    Website: https://www.luogu.com.cn/problem/P5718
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, x, minn = 0x3f3f3f3f;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        minn = min(minn, x);
    }
    printf("%d", minn);
    return 0;
}
/*
input:
8
1 9 2 6 0 8 1 7

output:
0
*/