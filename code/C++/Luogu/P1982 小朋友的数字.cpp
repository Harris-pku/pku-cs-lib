#include <cstdio>
#include <algorithm>
#define maxn 1000000

using namespace std;

long long f[maxn+100], s[maxn + 100], a[maxn + 100], n, p, ans, i, MAX;
int main(){
    scanf("%I64d%I64d", &n, &p);
    for (i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    f[1] = s[1] = MAX = a[1];
    for (i = 2; i <= n; i++){
        s[i] = max(s[i - 1] + a[i], a[i]);
        MAX = max(MAX, s[i]);
        f[i] = MAX;
    }
    ans = f[1] + f[1];
    for (i = 2; i < n; i++)
        if (f[i] > 0)
            ans = (ans + f[i]) % p;
    if (n == 1 || (f[1] < 0 && f[1] > ans))
        printf("%d", f[1] % p);
    else
        printf("%d", ans % p);
    return 0；
}
