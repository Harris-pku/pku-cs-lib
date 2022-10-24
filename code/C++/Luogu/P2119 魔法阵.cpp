#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[15005], b[15005], c[15005], d[15005], n, m;
int v[40005], num[15005];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d", &v[i]); num[v[i]]++;
    }
    for (int k = 1; k*9 < n; ++k){
        int sum = 0, ka, kb, kc, kd;
        for (kd = k*9+2; kd <= n; ++kd){
            ka = kd - 9*k - 1; kb = kd - 7*k - 1;
            kc = kd - k; sum += num[kb] *num[ka];
            c[kc] += num[kd] * sum;
            d[kd] += num[kc] * sum;
        }
        sum = 0;
        for (ka = n-k*9-1; ka >= 1; --ka){
            kb = ka + 2*k; kc = ka + k*8 + 1;
            kd = ka + k*9 + 1; sum += num[kc] * num[kd];
            a[ka] += num[kb] * sum;
            b[kb] += num[ka] * sum;
        }
    }
    for (int i = 1; i <= m; ++i)
        printf("%d %d %d %d\n", a[v[i]], b[v[i]], c[v[i]], d[v[i]]);
    return 0;
}
