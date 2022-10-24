#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[100005], n, m, l, r, mid, sum;
inline int can(int x){
    int cnt = 1, bef = 1;
    for (int i = 2; i <= n; ++i){
        if (a[i] - a[bef] >= x){
            bef = i; cnt++;
        }
        if (cnt >= m) return true;
    }
    return cnt >= m;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]); sum += a[i];
    }
    sort(a+1, a+n+1); r = a[n] - a[1];
    while (l <= r){
        mid = (l + r) >> 1;
        if (can(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", l - 1);
    return 0;
}