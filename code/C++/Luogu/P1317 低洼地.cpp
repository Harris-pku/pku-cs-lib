#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, cur, bef, flag, ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &cur);
        if (cur < bef) flag = 1;
        if (cur>bef && flag==1){
            ans++; flag = 0;
        }
        bef = cur;
    }
    printf("%d", ans);
    return 0;
}