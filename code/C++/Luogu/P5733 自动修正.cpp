/*  Coder: Harris
    Time: 2020.5.2
    Website: https://www.luogu.com.cn/problem/P5733
    Algorithm: simulation
*/
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

char s[105], len;
int main(){
    cin >> s;
    len = strlen(s);
    for (int i = 0; i < len; i++){
        if ('a'<=s[i] && s[i]<='z'){
            s[i] = s[i] - 'a' + 'A';
        }
    }
    cout << s;
    return 0;
}
/*
input:
Luogu4!

output:
LUOGU4!
*/