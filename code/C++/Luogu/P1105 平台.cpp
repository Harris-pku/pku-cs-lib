#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node{
    int h, l, r, num, ansl, ansr;
}a[1005];
int ans[20005], n;
int cmp1(const Node & x, const Node & y){
    return x.h == y.h ? x.num > y.num : x.h < y.h;
}
int cmp2(const Node & x, const Node & y){
    return x.num < y.num;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d%d", &a[i].h, &a[i].l, &a[i].r);
        a[i].num = i;
    }
    sort(a+1, a+n+1, cmp1);
    for (int i = 1; i <= n; ++i){
        a[i].ansr = ans[a[i].r]; a[i].ansl = ans[a[i].l];
        for (int j = a[i].l+1; j <= a[i].r-1; ++j){
        	ans[j] = a[i].num;
        }
    }
    sort(a+1, a+n+1, cmp2);
    for (int i = 1; i <= n; ++i){
        printf("%d %d\n", a[i].ansl, a[i].ansr);
    }
    return 0;
}
