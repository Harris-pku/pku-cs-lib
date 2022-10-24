#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[105], n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++){
        for (int j = n; j > i; j--){
            if (a[j] < a[j-1]) swap(a[j], a[j-1]);
        }
    }
    for (int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}