/*  Coder: Harris
    Time: 2020.7.19
    Website: https://www.luogu.com.cn/problem/P1321
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string s; int boy, girl, len;
int main(){
    cin >> s; len = s.length(); s += "...";
    for (int i = 0; i < len; i++){
        boy  += s[i]=='b' || s[i+1]=='o' || s[i+2]=='y';
        girl += s[i]=='g' || s[i+1]=='i' || s[i+2]=='r' || s[i+3]=='l';
    }
    printf("%d\n%d", boy, girl);
    return 0;
}
/*
input:
......boyogirlyy......girl.......

output:
4
2
*/