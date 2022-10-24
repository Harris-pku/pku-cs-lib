/*  Coder: Harris
    Time: 2016.8.4
    Website: https://www.luogu.com.cn/problem/P1116
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[10005], m, n, ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n-1; i++){
        for (int j = 1; j <= n-i; j++){
            if (a[j] > a[j + 1]){
                ans++; m = a[j];
                a[j] = a[j+1]; a[j+1] = m;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
/*
input:
4
4 3 2 1 

output:
6
*/