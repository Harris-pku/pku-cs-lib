/*  Coder: Harris
    Time: 2020.2.3
    Website: https://www.luogu.com.cn/problem/P2196
    Algorithm: DFS
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int a[25][25], b[25], f[25], cur[25], n, ans;
void dfs(int x, int sum){
    if (sum > ans){
        for (int i = 1; i <= n; i++){
            f[i] = cur[i];
        }
        ans = sum;
    }
    if (x >= n) return; 
    for (int i = x+1; i <= n; i++){
        if (!a[x][i]) continue;
        if (!cur[i]){
            cur[i] = 1;
            dfs(i, sum + b[i]);
            cur[i] = 0;
        }
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &b[i]); a[0][i] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++){
        if (f[i]) printf("%d ", i);
    }
    printf("\n%d", ans);
    return 0;
}
/*
input:
5
10 8 4 7 6
1 1 1 0
0 0 0
1 1
1

output:
1 3 4 5
27
*/