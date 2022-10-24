#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct home{
    int s, v;
    bool operator < (const home & x) const{
        return v > x.v;
    }
}a[100005];
int s[100005], h[100005], qm[100005], n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].s);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].v);
    sort(a+1, a+n+1);
    for (int i = n; i >= 1; --i)
        h[i] = max(h[i+1], 2*a[i].s + a[i].v);
    for (int i = 1; i <= n; ++i){
        qm[i] = max(qm[i-1], a[i].s);
        s[i] = s[i-1] + a[i].v;
        printf("%d\n", max(s[i-1]+h[i], s[i]+2*qm[i]));
    }
    return 0;
}