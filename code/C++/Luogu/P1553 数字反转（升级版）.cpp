/*  Coder: Harris
    Time: 2015.9.6
    Website: https://www.luogu.com.cn/problem/P1553
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

string s; char p; int cnt, x;
int main(){
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] >= '0' && s[i] <= '9')
            cnt++;
        else{
            p = s[i]; break;
        }
    }
    x = cnt--;
    while (s[cnt] == '0' && cnt > 0)
        cnt--;
    for (int i = cnt; i >= 0; i--){
        cout << s[i];
    }
    if (!p) return 0;
    else if (p == '%'){
        cout << p; return 0;
    }
    else{
        cout << p;
    }
    int m = s.size() - 1;
    while (s[x + 1] == '0' && x < m - 1)
        x++;
    while (s[m] == '0' && m > x + 1)
        m--;
    for (int i = m; i > x; i--){
        cout << s[i];
    }
    return 0;
}
/*
input:
600.084

output:
6.48
*/