#include <cstdio>
#include <algorithm>

using namespace std;

long long a[15], b[15], n, x, y;
int main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i], &b[i]);
    x = b[1]; y = a[1];
    for (int i = 2; i <= n; i++){
        while (x % a[i] != b[i])
            x += y;
        y *= a[i];
    }
    printf("%lld", x);
    return 0;
}
