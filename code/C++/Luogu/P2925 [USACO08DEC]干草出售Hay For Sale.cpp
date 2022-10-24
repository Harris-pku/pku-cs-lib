#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int f[50005] = {1}, n, m, cur, ans;
int main(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &cur);
        for (int j = m; j >= cur; --j){
            if (f[j-cur]) f[j] = 1;
        }
    }
    for (int i = m; i >= 0; --i){
        if (f[i]){
            ans = i; break;
        }
    }
    printf("%d", ans);
    return 0;
}
