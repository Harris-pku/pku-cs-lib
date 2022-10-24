#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int a[10005], n, k, l, r, mid; double cur;
int can(int x){
    int sum = 0;
    for (int i = 1; i <= n; ++i){
        sum += a[i] / x;
        if (sum >= k) return 1;
    }
    return 0;
}
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i){
        scanf("%lf", &cur); a[i] = (int) (cur * 10000);
        r = max(r, a[i]);
    }
    while (l < r){
        mid = (l+r+1) >> 1;
        if (can(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d.%02d", l/10000, l/100 % 100);
    return 0;
}
