#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, m, ans;
void dfs(int x, int y){
    if (x==n && y==m){
        ans++; return;
    }
    if (x>=n || y>m || y<0) return;
    dfs(x+1, y+2); dfs(x+2, y+1);
    dfs(x+1, y-2); dfs(x+2, y-1);
}
int main(){
    scanf("%d%d", &m, &n);
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}
