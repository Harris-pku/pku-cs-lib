/*  Coder: Harris
    Time: 2015.8.29
    Website: https://www.luogu.com.cn/problem/P1914
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, cur; char s[55];
int main(){
    scanf("%d", &n);
    n %= 26;
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++){
        cur = s[i] + n;
        while (cur > 'z')
            cur -= 26;
        s[i] = cur;
    }
    printf("%s", s);
    return 0;
}
/*
input:
1
qwe

output:
rxf
*/