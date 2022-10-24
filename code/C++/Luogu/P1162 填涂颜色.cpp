#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[35][35], n;
void dfs(int x,int y){
    if (a[x][y] != 0) return;
    a[x][y] = 2;
    dfs(x+1, y); dfs(x-1, y);
    dfs(x, y+1); dfs(x, y-1);
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i <= n+1; i++) 
        for (int j = 0; j <= n+1; j++)
            a[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++){
        dfs(1, i); dfs(i, 1);
        dfs(n, i); dfs(i, n);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            printf("%d%c", 2-a[i][j], j==n ? '\n' : ' ');
    return 0;
}
