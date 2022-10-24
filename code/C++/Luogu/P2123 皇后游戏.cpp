#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
    int x, y, d;
    bool operator < (const node & cur) const{
        if (d != cur.d) return d < cur.d;
        if (d <= 0) return x < cur.x;
        return y > cur.y;
    }
}a[20005];
long long c[20005]; int T, n;
int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i){
            scanf("%d%d", &a[i].x, &a[i].y);
            if (a[i].x > a[i].y) a[i].d = 1;
            else if (a[i].x < a[i].y) a[i].d = -1;
            else a[i].d = 0;
        }
        sort(a+1, a+n+1);
        long long sum = 0;
        for (int i = 1; i <= n; ++i){
            sum += a[i].x; c[i] = max(c[i-1], sum) + a[i].y;
        }
        printf("%lld\n", c[n]);
    }
    return 0;
}