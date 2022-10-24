#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[10005], b[10005], c[10005], n, m, x1, x2, y, y2;
int f[1000005], w[1000005], v[1000005], tot;
int main(){
    scanf("%d:%d %d:%d", &x1, &y, &x2, &y2);
    m = (x2-x1)*60 + y2-y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        if (!c[i]) c[i] = 9999999;
    }
    for (int i = 1; i <= n; ++i){
        int cur = 1;
        while (c[i]){
            w[++tot] = a[i]*cur;
            v[tot] = b[i]*cur;
            c[i] -= cur; cur <<= 1;
            if (c[i] < cur)
        }
    }
    return 0;
}