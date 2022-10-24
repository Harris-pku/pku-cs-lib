#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[1000005], n, l, r, mid; long long m;
int can(int x){
    long long sum = 0;
    for (int i = n; i >= 1; --i){
        if (a[i] <= x) break;
        sum += a[i] - x;
        if (sum >= m) return 1;
    }
    return sum >= m;
}
int main(){
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]); r = max(r, a[i]);
    }
    sort(a+1, a+n+1);
    while (l < r){
        mid = (l+r+1) >> 1;
        if (can(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d", l);
    return 0;
}
