#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[105], f[105], n, ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i){
        f[i] = 1;
        for (int j = 1; j < i; ++j){
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    printf("%d", ans);
    return 0;
}
