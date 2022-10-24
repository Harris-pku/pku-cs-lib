#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[105], n;
void merge(int l, int r, int mid){
    int idx1 = l, idx2 = mid + 1;
}
void mergesort(int l, int r){
    int mid = (l + r) >> 1;
    if (l < r){
        mergesort(l, mid);
        mergesort(mid+1, r);
        merge(l, r, mid);
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    mergesort(1, n);
    for (int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}