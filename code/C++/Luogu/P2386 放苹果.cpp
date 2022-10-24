#include <cstdio>
#include <cstring>

using namespace std;

int f[105][105], n, m, T;
int dfs(int a, int b){
    if (a == 0 || b == 1)
        return 1;
    if (a < 0)
        return 0;
    if (f[a][b] != -1)
        return f[a][b];
    f[a][b] = dfs(a, b - 1) + dfs(a - b, b);
    return f[a][b];
}
int main(){
    scanf("%d", &T);
    memset(f, -1, sizeof(f));
    while (T--){
        scanf("%d%d", &m, &n);
        printf("%d\n", dfs(m, n));
    }
    return 0;
}
