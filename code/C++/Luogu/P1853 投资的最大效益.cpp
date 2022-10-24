#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int f[50000005], w[50], c[50], s, n, d;
int main(){
    scanf("%d%d%d", &s, &n, &d);
    for (int i = 1; i <= d; ++i)
        scanf("%d%d", &w[i], &c[i]);
    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= d; ++i)
            for (int j = w[i]; j <= s; ++j)
                f[j] = max(f[j], f[j-w[i]] + c[i]);
        s += f[s];
    }
    printf("%d", s);
    return 0;
}
