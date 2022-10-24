/*  Coder: Harris
    Time: 2020.6.28
    Website: https://www.luogu.com.cn/problem/P5726
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstring>

using namespace std;

int n, x, sum, maxn, minn = 0x3f3f3f3f;
double ans;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        sum += x;
        maxn = max(maxn, x);
        minn = min(minn, x);
    }
    sum -= maxn + minn;
    ans = sum * 1.0 / (n-2);
    printf("%.2f", ans);
    return 0;
}
/*
input:
5
9 5 6 8 9

output:
7.67
*/