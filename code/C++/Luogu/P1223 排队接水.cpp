#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct people{
    int id, num;
    bool operator < (const people & x) const {
        return num < x.num;
    }
} t[1005];
int n; double ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &t[i].num);
        t[i].id = i;
    }
    sort(t+1, t+n+1);
    for (int i = 1; i <= n; i++){
        ans += t[i].num * (n-i);
    }
    for (int i = 1; i <= n; i++){
        printf("%d ", t[i].id);
    }
    printf("\n%.2f", ans / n);
    return 0;
}