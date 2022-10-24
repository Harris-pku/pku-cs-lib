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
    for (int i = 2; i <= n; i++){
        int cur = a[i], j = i - 1;
        while (a[j]>cur && j>=1){
            a[j+1] = a[j]; j--;    
        }
        a[j+1] = cur;
    }
    for (int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}