#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define int128 __int128

using namespace std;

const int maxn = 40000005;
const int p = 1073741824;
int k, n, x, y, z, m, t, l, r, cur = 1, head = 1, tail = 1;
int f[maxn], q[maxn]; int128 ans;
long long sum[maxn], b1, b2, b3, w;
void init(){
    scanf("%d%d%d%lld%lld%d", &x, &y, &z, &b1, &b2, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d%d", &t, &l, &r);
        while (cur <= t){
            if (cur == 1){
                w = (b1%(r-l+1)) + l; sum[1] = w;
            }
            else if (cur == 2){
                w = (b2%(r-l+1)) + l; sum[2] = sum[1] + w;
            }
            else{
                b3 = (x*b2+y*b1+z) % p;
                w = (b3%(r-l+1)) + l; sum[cur] = sum[cur-1] + w;
                b1 = b2; b2 = b3;
            }
            cur++;
        }
    }
}
void out(int128 t){
    if (t > 9)
        out(t/10);
    putchar(t%10 + '0');
}
int main(){
    scanf("%d%d", &n, &k);
    if (k) init();
    else{
        for (int i = 1; i <= n; ++i){
            scanf("%lld", &w); sum[i] = sum[i-1] + w;
        }
    }
    for (int i = 1; i <= n; ++i){
        while (head<tail && 2*sum[q[head+1]]-sum[f[q[head+1]]]<=sum[i])
            head++;
        f[i] = q[head];
        while (head<tail && 2*sum[q[tail]]-sum[f[q[tail]]]>=2*sum[i]-sum[q[head]])
            tail--;
        q[++tail] = i;
    }
    cur = n;
    while (cur){
        ans += (int128)(sum[cur]-sum[f[cur]])*(sum[cur]-sum[f[cur]]);
        cur = f[cur];
    }
    out(ans);
    return 0;
}