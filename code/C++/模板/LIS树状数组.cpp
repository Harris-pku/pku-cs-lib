#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct node {
    int pos, val;
    bool operator < (const node & x) const {
        if (val == x.val) return pos > x.pos;
        return val < x.val;
    }
}a[300005];

int c[300005], n, k, cur;
inline int lowbit(int x) {
    return x & (-x);
}
inline void update(int x, int y){
    for (int i = x; i <= n; i += lowbit(i)) {
        c[i] = max(c[i], y);
    }
}
inline int getmax(int x){
    int maxn = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        maxn = max(maxn, c[i]);
    }
    return maxn;
}
inline void solve(){
    for (int i = 1; i <= n; ++i) {
        cur = getmax(a[i].pos) + 1;
        update(a[i].pos, cur);
    }
    printf("%d\n", getmax(n));
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        a[i].pos = i; a[i].val = k;
    }
    sort(a+1, a+n+1);
    solve();
    return 0;
}