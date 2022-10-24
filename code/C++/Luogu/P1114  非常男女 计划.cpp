#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int l[200005], r[200005], n, cur, ans, sum1, sum0;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &cur);
        sum1 += (cur==1); sum0 += (cur==0);
        cur = sum0 - sum1 + n;
        if (!l[cur] && cur!=n) l[cur] = i;
        else r[cur] = i;
    }
    for (int i = 0; i <= n*2; ++i)
        ans = max(ans, r[i]-l[i]);
    printf("%d", ans);
    return 0;
}
