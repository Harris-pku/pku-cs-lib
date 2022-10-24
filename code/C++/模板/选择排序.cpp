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
        int cur = i;
        for (int j = i+1; j <= n; j++){
            if (a[j] < a[cur]) cur = j;
        }
        swap(a[i], a[cur]);
    }
    for (int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}