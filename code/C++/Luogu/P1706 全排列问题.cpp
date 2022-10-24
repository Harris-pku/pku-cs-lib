#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[15], n, m = 1;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        a[i] = i; m *= i;
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++)
            printf("%5d", a[j]);
        printf("\n");
        next_permutation(a+1, a+n+1);
    }
    return 0;
}
