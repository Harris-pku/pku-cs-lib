/*  Coder: Harris
    Time: 2020.7.19
    Website: https://www.luogu.com.cn/problem/P2006
    Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int k, m, n, a, b, x, flag = 1;
int main(){
    scanf("%d%d%d", &k, &m, &n);
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &a, &b);
        if (((!a)&&b) || (a&&(k/a)*b>=n)){
            flag = 0; printf("%d ", i);
        }
    }
    if (flag) printf("-1");
    return 0;
}
/*
input:
100 3 5000
20 1000
90 1
110 10000

output:
1
*/