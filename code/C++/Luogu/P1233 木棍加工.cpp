#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

struct bar{
    int l, w;
    bool operator < (const bar & x) const{
        return l > x.l;
    }
}a[5005];
int f[5005], ans, n, mid;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].l, &a[i].w);
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i)
        if (a[i].w > f[ans])
            f[++ans] = a[i].w;
        else{
            int l = 1, r = ans;
            while (l < r){
                mid = (l+r) >> 1;
                if (f[mid] >= a[i].w) r = mid;
                else l = mid + 1;
            }
            f[l] = a[i].w;
        }
    printf("%d", ans);
    return 0;
}