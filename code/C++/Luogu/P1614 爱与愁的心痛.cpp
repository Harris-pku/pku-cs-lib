/*  Coder: Harris
    Time: 2016.8.10
    Website: https://www.luogu.com.cn/problem/P1614
    Algorithm: simulation
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[3005], s[3005], n, m, ans;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    ans = s[m];
    for (int i = m+1; i <= n; ++i){
        ans = min(ans, s[i]-s[i-m]);
    }
    printf("%d", ans);
    return 0;
}
/*
input:
8 3
1
4
7
3
1
2
4
3

output:
6
*/