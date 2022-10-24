#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000005, p = 1e9 + 7;
long long f[maxn] = {1}, inv[maxn], d[maxn], n, m; int T;
long long qpow(long long x, long long y){
    long long ans = 1;
    while (y){
        if (y&1) ans = x*ans % p;
        x = x*x % p;
        y >>= 1;
    }
    return ans;
}
int main(){
    scanf("%d", &T);
    for (int i = 1; i < maxn; ++i){
        f[i] = f[i-1]*i % p;
        inv[i] = qpow(f[i], p - 2);
    }
    d[1] = 0; d[2] = 1; d[3] = 2;
    for (int i = 4; i < maxn; ++i)
        d[i] = (i-1) * (d[i-1] + d[i-2]) % p;
    while (T--){
        scanf("%lld%lld", &n, &m);
        if (n - m == 1) printf("0\n");
        else if (m == n) printf("1\n");
        else if (m == 0) printf("%lld\n", d[n]);
        else{
            printf("%lld\n", f[n]*inv[m] % p * inv[n-m] % p * d[n-m] % p);
        }
    }
    return 0;
}