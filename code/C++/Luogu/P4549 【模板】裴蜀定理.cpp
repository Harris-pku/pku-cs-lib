#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, cur, ans;
inline int gcd(int a, int b){
    if (!b) return a;
    return gcd(b, a%b);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &cur);
        if (cur < 0) cur = -cur;
        ans = gcd(ans, cur);
    }
    printf("%d", ans);
    return 0;
}