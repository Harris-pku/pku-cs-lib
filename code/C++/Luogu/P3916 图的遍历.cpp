#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> G[100005];
int ans[100005], n, m, u, v;
void dfs(int x, int t){
    if (ans[x]) return;
    ans[x] = t;
    for (int i = 0; i < G[x].size(); ++i){
        dfs(G[x][i], t);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &u, &v);
        G[v].push_back(u);
    }
    for (int i = n; i; --i)
        dfs(i, i);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    return 0;
}