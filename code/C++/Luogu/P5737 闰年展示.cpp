/*  Coder: Harris
    Time: 2020.5.3
    Website: https://www.luogu.com.cn/problem/P5737
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a, b, s, c[3005];

bool is_run(int n){
    if (n%400==0 || (n%4==0 && n%100!=0)) return true;
    return false;
}

int main(){
    cin >> a >> b;
    for (int i = a; i <= b; i++){
        if (is_run(i)){
            s++; c[s] = i;
        }
    }
    printf("%d\n", s);
    for (int i = 1; i <= s; i++){
        printf("%d ", c[i]);
    }
    return 0;
}
/*
input:
1989 2001

output:
3
1992 1996 2000
*/