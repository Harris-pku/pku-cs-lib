/*  Coder: Harris
    Time: 2020.5.5
    Website: https://www.luogu.com.cn/problem/P1591
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[200005], len;
void cheng(int k){ // a * k
    for (int i = 1; i <= len; i++){
        a[i] *= k;
    }
    for (int i = 1; i <= len; i++){
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }
    while (a[len+1]){
        len++;
        a[len+1] = a[len] / 10;
        a[len] %= 10;
    }
}
int T, n, k;
int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &k);
        memset(a, 0, sizeof(a));
        a[1] = 1; len = 1;
        for (int i = 2; i <= n; i++){
            cheng(i);
        }
        int ans = 0;
        for (int i = 1; i <= len; i++){
            if (a[i] == k) ans++;
        }
        printf("%d\n", ans);
    }    
    return 0;
}
/*
input:
2
5 2
7 0

output:
1
2
*/