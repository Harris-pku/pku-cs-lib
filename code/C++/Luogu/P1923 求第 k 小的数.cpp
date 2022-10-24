/*  Coder: Harris
    Time: 2020.6.30
    Website: https://www.luogu.com.cn/problem/P1923
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[5000005], n, k;
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    nth_element(a, a+k, a+n);
    printf("%d", a[k]);
    return 0;
}
/*
input:
5 1
4 3 2 1 5

output:
2
*/