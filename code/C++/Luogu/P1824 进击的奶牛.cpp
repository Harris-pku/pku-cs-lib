#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a[100005],n, m, l, r, mid;
int can(int x){
    int tot = 0, bef = 1;
    for (int i = 2; i <= n; ++i){
        if (a[i] - a[bef] >= x){
            if (++tot == m-1) return 1;
            bef = i;
        }
    }
    return 0;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        r = max(r, a[i]);
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
