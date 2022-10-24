#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
    long long a, b, c;
    bool operator < (const node & x) const{
        return x.b*c < b*x.c;
    }
}a[55];
int T, n; long long f[100005], ans;
int main(){
    scanf("%d%d", &T, &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].a);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].b);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].c);
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i)
        for (int j = T; j >= a[i].c; --j){
            f[j] = max(f[j], f[j-a[i].c]+a[i].a-a[i].b*j);
            ans = max(ans, f[j]);
        }
    printf("%lld", ans);
    return 0;
}