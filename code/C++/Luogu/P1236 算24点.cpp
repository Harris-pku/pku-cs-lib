#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int a[5][11], ans[11][3], ky[11]; bool flg;
char op(int k){
    switch (k){
        case 1:
            return '+';
        case 2:
            return '-';
        case 3:
            return '*';
        default:
            return '/';
    }
}
int calc(int x, int y, int k){
    switch (k){
        case 1:
            return x + y;
        case 2:
            return x - y;
        case 3:
            return x * y;
        default:
            return x / y;
    }
}
void print(int dep){
    if (dep == 1)
        return;
    printf("%d%c%d=%d\n", ans[dep][1], op(ky[dep]), ans[dep][2], a[dep - 1][1]);
    print(dep - 1);
}

void dfs(int dep){
    if (flg)
        return;
    if (dep == 1){
        if (a[1][1] == 24){
            flg = 1; print(4);
        }
        return;
    }
    for (int i = 1; i <= dep; i++)
        for (int j = 1; j <= dep; j++)
            if (i != j){
                ans[dep][1] = max(a[dep][i], a[dep][j]), ans[dep][2] = min(a[dep][i], a[dep][j]);
                for (int k = 1; k <= 4; k++){
                    if ((k == 2 && a[dep][i] <= a[dep][j]) || (k == 4 && a[dep][j] != 0 && a[dep][i] % a[dep][j] != 0))
                        continue;
                    int tp = 1;
                    a[dep - 1][tp] = calc(a[dep][i], a[dep][j], k);
                    for (int g = 1; g <= dep; g++)
                        if (g != i && g != j)
                            a[dep - 1][++tp] = a[dep][g];
                    ky[dep] = k;
                    dfs(dep - 1);
                }
            }
}
int main(){
    for (int i = 1; i <= 4; i++)
        scanf("%d", &a[4][i]);
    dfs(4);
    if (!flg)
        printf("No answer!\n");
    return 0;
}
