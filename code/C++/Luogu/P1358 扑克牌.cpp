#include <iostream>
#include <cstdio>

using namespace std;

int c[20000][200], n, m, k, ans = 1;
int main(){
    scanf("%d%d", &n, &m);
    c[0][0] = 1;
    for (int i = 1; i <= 10001; ++i){
        c[i][0] = 1;
        for (int j = 1; j <= 101; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 10007;
    }
    for (int i = 1; i <= m; ++i){
        scanf("%d", &k);
        ans = ans * c[n][k] % 10007;
        n -= k;
        if (n < 0)
            break;
    }
    printf("%d", ans);
    return 0;
}
