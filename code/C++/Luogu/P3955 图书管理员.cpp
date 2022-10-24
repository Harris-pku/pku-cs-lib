#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[1005], n, q, l, code;
int mod[9] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int judge(){
    for (int i = 1; i <= n; ++i){
        if (a[i]%mod[l] == code) return a[i];
    }
    return -1;
}
int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for (int i = 1; i <= q; ++i){
        scanf("%d%d", &l, &code);
        printf("%d\n", judge());
    }
    return 0;
} 