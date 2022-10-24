/*  Coder: Harris
    Time: 2016.8.20
    Website: https://www.luogu.com.cn/problem/P2141
    Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[100005], p[100005], x, n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]); p[a[i]] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
            if (p[a[i]+a[j]] == 1){
                x++; p[a[i]+a[j]] = 0;
            }
        }
    }
    printf("%d", x);
    return 0; 
}
/*
input:
4
1 2 3 4

output:
2
*/