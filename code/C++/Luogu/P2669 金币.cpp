/*  Coder: Harris
    Time: 2015.12.26
    Website: https://www.luogu.com.cn/problem/P2669
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int k, ans, n = 1;
int main(){
    scanf("%d", &k);
    while (n <= k){
        ans += n * n;
        k -= n; n++;
    }
    ans += n * k;
    printf("%d", ans);
    return 0;
}
/*
input:
1000

output:
29820
*/