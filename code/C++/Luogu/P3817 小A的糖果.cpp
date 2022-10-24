/*  Coder: Harris
    Time: 2020.7.19
    Website: https://www.luogu.com.cn/problem/P3817
    Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[200005], n, x; long long ans;
int main(){
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++){
        ans += max(0, a[i-1]+a[i]-x);
        a[i] -= max(0, a[i-1]+a[i]-x);
    }
    cout << ans;
    return 0;
}
/*
input:
6 1
1 6 1 2 0 4

output:
11
*/