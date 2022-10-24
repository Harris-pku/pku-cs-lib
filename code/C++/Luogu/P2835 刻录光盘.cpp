/*  Coder: Harris
    Time: 2019.8.28
    Website: https://www.luogu.com.cn/problem/P2835
    Algorithm: use Union-Find to calculate connected section
               使用并查集计算单向连通块
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fa[205], ru[205], n, ans;
int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int main(){
    scanf("%d", &n); int x;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i){
        while (scanf("%d", &x) && x){
            fa[found(x)] = found(i); ru[x]++;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (fa[i] == i) ans++;
        else if (!ru[i]) ans++;
    printf("%d", ans);
    return 0;
}
/*
input:
5
2 3 4 0
4 5 0
0
0
1 0

output:
1
*/