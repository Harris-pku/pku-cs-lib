#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[1000005], n, m, l, r, mid, maxn;
bool can(int x){
    long long cnt = 0;
    for (int i = 1; i <= n; ++i){
        cnt += a[i] / x;
        if (cnt >= m) break;
    }
    return cnt >= m;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]); maxn = max(maxn, a[i]);
    }
    l = 0; r = maxn;
    while (l <= r){
        mid = (l + r) >> 1;
        if (!mid){
        	printf("0"); return 0;
        } 
        if (can(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d", l - 1);
    return 0;
}
