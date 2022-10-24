/*  Coder: Harris
    Time: 2020.7.3
    Website: https://www.luogu.com.cn/problem/P4956
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int x;
int main(){
    scanf("%d", &x);
    x /= 52 * 7;
    for (int i = min(100, x-3); i > 0; i--){
        if ((x-i) % 3 == 0){
            printf("%d\n%d", i, (x-i) / 3); break;
        }
    }
    return 0;
}
/*
input:
6188

output:
14
1
*/