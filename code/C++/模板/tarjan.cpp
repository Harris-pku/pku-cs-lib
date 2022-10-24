#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10005;
const int maxm = 50005;

int dfn[maxn], low[maxn], st[maxn], x, y, cnt, top;
int h[maxn], nex[maxm], to[maxm], inst[maxn], n, m;
void tarjan(int u){
    dfn[u] = low[u] = ++cnt;
    st[top++] = u; inst[u] = 1;
    for (int i = h[u]; i; i = nex[i]){
        int v = to[i];
        if (!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inst[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]){
        while (1){
            int v = st[--top];
            printf("%d ", v);
            inst[v] = 0;
            if (u == v) break;
        }
        printf("\n");
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y);
        nex[i] = h[x]; to[i] = y; h[x] = i;
    }
    for (int i = 1; i <= n; ++i){
        if (!dfn[i]) tarjan(i);
    }
    return 0;
}