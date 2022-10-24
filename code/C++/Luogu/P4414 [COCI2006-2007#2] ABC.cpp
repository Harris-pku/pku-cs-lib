/*  Coder: Harris
    Time: 2020.7.8
    Website: https://www.luogu.com.cn/problem/P4414
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[3]; char A, B, C;
int main(){
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    sort(a, a+3);
    cin >> A >> B >> C;
    printf("%d %d %d", a[A-'A'], a[B-'A'], a[C-'A']);
    return 0;
}
/*
input:
1 5 3
ABC

output:
1 3 5
*/