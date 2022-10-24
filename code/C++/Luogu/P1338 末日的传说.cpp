#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, pos, t, bef, cur;
int main(){
    scanf("%d%d", &n, &m); pos = n;
    for (int i = 1; m; i++, pos--)
        m -= t = min(i, m);
    for (int i = 1; i < pos; ++i)
        printf("%d ", i);
    printf("%d ", pos+t);
    for (int i = n; i >= pos; --i)
        if (i != pos+t) printf("%d ", i);
    return 0;
}
