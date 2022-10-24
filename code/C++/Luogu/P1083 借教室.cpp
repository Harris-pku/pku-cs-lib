#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1000005;
int rest[maxn], d[maxn], s[maxn], t[maxn], n, m;
int diff[maxn], need[maxn], l, r, mid;
int can(int x){
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i <= x; ++i){
        diff[s[i]] += d[i]; diff[t[i]+1] -= d[i];
    }
    for (int i = 1; i <= n; ++i){
        need[i] = need[i-1] + diff[i];
        if (need[i] > rest[i]) return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &rest[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &d[i], &s[i], &t[i]);
    l = 1; r = m;
    if (can(m)){
        printf("0"); return 0;
    }
    while (l < r){
        mid = (l + r) >> 1;
        if (can(mid)) l = mid + 1;
        else r = mid;
    }
    printf("-1\n%d", l);
    return 0;
}
