#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

long long cur, bef, ans; int h[5005], n;
int solve(int l, int r, int low){
    if (l == r) return 1;
    int hei = 0x3f3f3f3f, tmp = 0;
    for (int i = l; i <= r; ++i)
        hei = min(hei, h[i]);
    for (int i = l, j; i <= r; ++i){
        if (h[i] == hei) continue;
        for (j = i; j<r && h[j+1]>hei; ++j);
            tmp += solve(i, j, hei);
        i = j;
    }
    return min(r-l+1, hei-low+tmp);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);
    printf("%d", solve(1, n, 0));
    return 0;
}
