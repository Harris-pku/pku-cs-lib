/*  Coder: Harris
    Time: 2020.5.3
    Website: https://www.luogu.com.cn/problem/P5738
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

double ans; int n, m, a[25];
double score(){
    int sum = 0, maxn = 0, minn = 10;
    for (int i = 1; i <= m; i++){
        sum += a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    sum -= maxn + minn;
    double x = (sum * 1.0) / (m-2);
    return x;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%d", &a[j]);
        }
        ans = max(ans, score());
    }
    printf("%.2f", ans);
    return 0;
}
/*
input:
7 6
4 7 2 6 10 7
0 5 0 10 3 10
2 6 8 4 3 6
6 3 6 7 5 8
5 9 3 3 8 1
5 9 9 3 2 0
5 8 0 4 1 10

output:
6.00
*/