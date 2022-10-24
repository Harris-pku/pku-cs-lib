/*  Coder: Harris
    Time: 2020.7.18
    Website: https://www.luogu.com.cn/problem/P1957
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[55]; int n, a, b, x; char c;
int main(){
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++){
        cin.getline(s, 50);
        if ('a' <= s[0] && s[0] <= 'c'){
            sscanf(s, "%c %d %d", &c, &a, &b);
        }
        else sscanf(s, "%d %d", &a, &b);
        if (c == 'a') sprintf(s, "%d+%d=%d", a, b, a+b);
        if (c == 'b') sprintf(s, "%d-%d=%d", a, b, a-b);
        if (c == 'c') sprintf(s, "%d*%d=%d", a, b, a*b);
        cout << s << endl << strlen(s) << endl;
    }
    return 0;
}
/*
input:
4
a 64 46
275 125
c 11 99
b 46 64

output:
64+46=110
9
275+125=400
11
11*99=1089
10
46-64=-18
9
*/