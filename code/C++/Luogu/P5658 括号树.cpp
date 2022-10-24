#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int v[500005], nex[500005], h[500005], fa[500005];
int s[500005], top, n, x, y, tot;
long long lst[500005], sum[500005], ans; char ss[500005];
void dfs(int x){
    int cur = 0;
    if (ss[x] == ')'){
        if (top){
            cur = s[top--]; lst[x] = lst[fa[cur]] + 1;
        }
    }
    else if (ss[x] == '(') s[++top] = x;
    sum[x] = sum[fa[x]] + lst[x];
    for (int i = h[x]; i; i = nex[i])
        dfs(v[i]);
    if (cur) s[++top] = cur;
    else if (top) --top;
}
int main(){
    scanf("%d", &n);
    scanf("%s", ss+1);
    for (int i = 2; i <= n; ++i){
        scanf("%d", &x); fa[i] = x;
        v[++tot] = i; nex[tot] = h[x]; h[x] = tot;
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        ans ^= sum[i] * (long long)i;
    printf("%lld", ans);
    return 0;
}