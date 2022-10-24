/*  Coder: Harris
    Time: 2015.8.27
    Website: https://www.luogu.com.cn/problem/P1059
    Algorithm: sort with a budget
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[1005], n, cur, tot;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &cur);
        if (!a[cur]) tot++; a[cur] = 1;
    }
    printf("%d\n", tot);
    for (int i = 1; i <= 1000; i++)
        if (a[i]) printf("%d ", i);
    return 0;
}
/*
input:
10
20 40 32 67 40 20 89 300 400 15

output:
8
15 20 32 40 67 89 300 400
*/