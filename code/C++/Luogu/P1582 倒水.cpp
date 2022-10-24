#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, k, ans;
inline int lowbit(int x){
    return x & -x;
}
inline int cnt(int x){
    int num = 0;
    while (x){
        num++; x -= lowbit(x);
    }
    return num;
}
int main(){
    scanf("%d%d", &n, &k);
    while (cnt(n) > k){
        ans += lowbit(n); n += lowbit(n);
    }
    printf("%d", ans);
    return 0;
}