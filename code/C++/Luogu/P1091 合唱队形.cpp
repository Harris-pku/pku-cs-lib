#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[105], f[105], g[105], n, ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            if (a[j] < a[i]) f[i] = max(f[i], f[j]+1);
        }
    }
    for (int i = n; i >= 1; i--){
        for (int j = n+1; j > i; j--){
            if (a[j] < a[i]) g[i] = max(g[i], g[j]+1);
        }
    }
    for (int i = 1; i <= n; i++){
        ans = max(ans, f[i]+g[i]-1);
    }
    printf("%d", n-ans);
    return 0;
}