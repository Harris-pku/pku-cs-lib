#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int w[10005], s[105], n, m, cur;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; ++i){
        cur = 1;
        for (int j = 2; j <= m; ++j)
            if (s[cur] > s[j]) cur = j;
        s[cur] += w[i];
    }
    for (int i = 1; i <= m; ++i)
        cur = max(cur, s[i]);
    printf("%d", cur);
    return 0;
}