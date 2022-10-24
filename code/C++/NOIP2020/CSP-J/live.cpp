#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[605], n, x, w;
int main(){
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        a[x]++;
        int cur = 0;
        for (int j = 600; j >= 0; j--){
            if (a[j]){
                cur += a[j];
                if (cur >= i * w / 100){
                    printf("%d ", j); break;
                }
            }
        }
    }
    return 0;
}