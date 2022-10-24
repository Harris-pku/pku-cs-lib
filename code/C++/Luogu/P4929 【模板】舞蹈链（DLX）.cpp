#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 250505;
int l[maxn], r[maxn], u[maxn], d[maxn], col[maxn], row[maxn];
int h[maxn], s[maxn], ansk[maxn], n, m, cnt, x;
inline void link(int R, int C){
    s[C]++; row[cnt] = R; col[cnt] = C;
    u[cnt] = C; d[cnt] = d[C]; u[d[C]] = cnt; d[C] = cnt;
    if (h[R] == -1) h[R] = r[cnt] = l[cnt] = cnt;
    else{
        r[cnt] = h[R]; l[cnt] = l[h[R]]; r[l[h[R]]] = cnt; l[h[R]] = cnt;
    }
    cnt++;
    return;
}
inline void remove(int C){
    r[l[C]] = r[C]; l[r[C]] = l[C];
    for (int i = d[C]; i != C; i = d[i])
        for (int j = r[i]; j != i; j = r[j]){
            u[d[j]] = u[j]; d[u[j]] = d[j]; s[col[j]]--;
        }
}
inline void resume(int C){
    for (int i = u[C]; i != C; i = u[i])
        for (int j = l[i]; j != i; j = l[j]){
            u[d[j]] = j; d[u[j]] = j; s[col[j]]++;
        }
    r[l[C]] = l[r[C]] = C;
}
bool dance(int deep){
    if (!r[0]){
        for (int i = 0; i < deep; ++i)
            printf("%d ", ansk[i]);
        return 1;
    }
    int c = r[0];
    for (int i = r[0]; i != 0; i = r[i])
        if (s[i] < s[c]) c = i;
    remove(c);
    for (int i = d[c]; i != c; i = d[i]){
        ansk[deep] = row[i];
        for (int j = r[i]; j != i; j = r[j])
            remove(col[j]);
        if (dance(deep+1)) return 1;
        for (int j = l[i]; j != i; j = l[j])
            resume(col[j]);
    }
    resume(c);
    return 0;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; ++i){
        r[i] = i+1; l[i] = i-1; u[i] = d[i] = i;
    }
    r[m] = 0; l[0] = m; cnt = m+1;
    memset(h, -1, sizeof(h));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            scanf("%d", &x); if (x) link(i, j);
        }
    }
    if (!dance(0)) printf("No Sulution!");
    return 0;
}