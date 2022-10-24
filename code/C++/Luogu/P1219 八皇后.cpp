#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int ans[15], f[5][30], sum, n;
void dfs(int x){
    if (x == n+1){
        if(++sum > 3) return;
        else{
            for (int i = 1; i <= n; i++) 
				printf("%d ", ans[i]);
            printf("\n");
            return;
        }
    }
    for (int i = 1; i <= n; i++){
        if((!f[0][i]) && (!f[1][x+i-1]) && (!f[2][n-x+i])){
            ans[x] = i;
            f[0][i] = 1; f[1][x+i-1] = 1; f[2][n-x+i] = 1;
            dfs(x + 1);
            f[0][i] = 0; f[1][x+i-1] = 0; f[2][n-x+i] = 0;
        }
    }
}
int main(){
    scanf("%d", &n);
    dfs(1);
    printf("%d", sum);
    return 0;
}