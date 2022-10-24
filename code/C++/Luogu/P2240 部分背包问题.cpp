/*  Coder: Harris
    Time: 2020.7.19
    Website: https://www.luogu.com.cn/problem/P2240
    Algorithm: greedy algorithm
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct gold{
    int m, v; double par;
    void scanf_info(){
        scanf("%d%d", &m, &v);
        par = v * 1.0 / m;
    }
    bool operator < (const gold & x) const {
        return par > x.par;
    }
} a[105];
int n, t; double ans;
int main(){
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++){
        a[i].scanf_info();
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n && t > 0; i++){
        ans += a[i].par * min(a[i].m, t);
        t -= min(a[i].m, t);
    }
    printf("%.2f", ans);
    return 0;
}
/*
input:
4 50
10 60
20 100
30 120
15 45

output:
240.00
*/