#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

long long a[1005][1005], s[1005][1005], ans, cur;
int n, m, k, x, y;
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i){
        cur = 0;
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            cur += a[i][j]; s[i][j] = s[i-1][j] + cur;
        }
    }
    for (int i = 1; i <= n - k + 1; ++i){
        for (int j = 1; j <= m - k + 1; ++j){
            if (s[i+k-1][j+k-1] - s[i-1][j+k-1] - s[i+k-1][j-1] + s[i-1][j-1] > ans){
                ans = s[i+k-1][j+k-1] - s[i-1][j+k-1] - s[i+k-1][j-1] + s[i-1][j-1]; x = i; y = j;
            }
        }
    }
    printf("%d %d", x, y);
    return 0;
}
