#include <cstdio>
#include <algorithm>

using namespace std;

int a[300005], b[300005], num[2][300005];
int n, m;
void LCS(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                num[i&1][j] = num[(i-1)&1][j-1] + 1;
            else
                num[i&1][j] = max(num[i&1][j-1], num[(i-1)&1][j]);
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    LCS();
    printf("%d\n", num[n&1][m]);
    return 0
}
