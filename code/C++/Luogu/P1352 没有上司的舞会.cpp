#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[6005][2], nex[12005], h[12005], f[12005], n, a, b, root;
void dfs(int x){
    for (int i = h[x]; i; i = nex[i]){
        dfs(i);
        dp[x][1] = max(dp[x][1]+max(0, dp[i][0]), dp[i][0]);
        dp[x][0] = max(dp[x][0]+max(0, dp[i][1]), max(dp[i][1], dp[i][0]));
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &dp[i][1]);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &a, &b);
        f[a] = 1; nex[a] = h[b]; h[b] = a;
    }
    for (int i = 1; i <= n; i++)
        if (!f[i]){
            root = i; break;
        }
    dfs(root);
    printf("%d", max(dp[root][0], dp[root][1]));
    return 0;
}
