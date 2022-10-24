#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[300005], s[300005], n, tot, *tmp;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    s[++tot] = a[1];
    for (int i = 2; i <= n; ++i){
        if (a[i] > s[tot])
            s[++tot] = a[i];
        else{
            tmp = lower_bound(s+1, s+tot+1, a[i]);
            *tmp = a[i];
        }
    }
    printf("%d", tot);
    return 0;
}
