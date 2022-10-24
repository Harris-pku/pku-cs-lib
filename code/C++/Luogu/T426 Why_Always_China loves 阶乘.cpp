#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[10010] = {0, 1}, len = 1, n, m;
void mult(int k){
    int j = 0;
    for (int i = 1; i <= len; i++){
        a[i] = a[i] * k + j;
        j = a[i] / 10000;
        a[i] %= 10000;
    }
    while (j){
        a[++len] = j; j /= 10000;
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        mult(i);
    printf("%d", a[len]);
    for (int i = len - 1; i >= 1; i--)
        printf("%04d", a[i]);
    while (n){
        m = m + (n / 5);
        n /= 5;
    }
    printf("\n%d", m);
    return 0;
}
