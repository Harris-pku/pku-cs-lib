#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int s[1005], a[1005], n, m, x, y, ans;
// s[i] 表示 a[1] 到 a[i] 的和
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        int ans = 0;
        for (int j = x; j <= y; j++){
            ans += a[j];
        }
        printf("%d %d\n", ans, s[y]-s[x-1]);
    }
    return 0;
}