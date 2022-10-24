/*  Coder: Harris
    Time: 2020.2.2
    Website: https://www.luogu.com.cn/problem/P1244
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int h, k;
int main(){
    scanf("%d%d", &h, &k);
    printf("%d", (k+1) * (1<<h));
    return 0;
}
/*
input:
2 3

output:
16
*/