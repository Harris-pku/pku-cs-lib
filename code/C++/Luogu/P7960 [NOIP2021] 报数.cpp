/*  Coder: Harris
    Time: 2022.10.25
    Website: https://www.luogu.com.cn/problem/P5720
    Algorithm: simulation
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e7 + 15;

int T, cur, n;
int f[maxn], suc[maxn];
int check(int x){
    while (x){
        if (x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}
int main(){
    for (int i = 1; i < maxn - 5; i++){
        if (f[i]) continue;
        if (check(i)){
            for (int j = i; j < maxn - 5; j += i){
                f[j] = 1;
            }
            continue;
        }
        suc[cur] = i;
        cur = i;
    }
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        if (f[n]) printf("-1\n");
        else printf("%d\n", suc[n]);
    }
    return 0; 
}
/*
input:
4
6
33
69
300

output:
8
36
80
-1
*/