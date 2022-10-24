/*  Coder: Harris
    Time: 2020.1.31
    Website: https://www.luogu.com.cn/problem/P5690
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int h[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, m, ans = 5;
inline int check(int x, int y){
    int tmp = 0;
    if (x%10 != y%10) tmp++;
    if (x/10 != y/10) tmp++;
    return tmp;
}
int main(){
    scanf("%d-%d", &n, &m);
    for (int i = 1; i <= 12; i++){
        for (int j = 1; j <= h[i-1]; j++){
            ans = min(ans, check(n, i) + check(m, j));
        }
    }
    printf("%d", ans);
    return 0;
}
/*
input:
03-32

output:
1
*/