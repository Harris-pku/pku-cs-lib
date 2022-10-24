#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

long long inv[3000005] = {0, 1}; int n, m;
int main(){
    scanf("%d%d", &n, &m); printf("1\n");
    for (int i = 2; i <= n; ++i){
        inv[i] = (long long)m - (m/i) * inv[m%i] % m;
        printf("%d\n", inv[i]);
    }
    return 0;
}