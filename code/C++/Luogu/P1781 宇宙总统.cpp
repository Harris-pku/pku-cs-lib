/*  Coder: Harris
    Time: 2015.8.28
    Website: https://www.luogu.com.cn/problem/P1781
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

bool larger(string a, string b){
    if (a.length() != b.length()){
        return a.length() > b.length();
    }
    return a > b;
}
int n, x = 1; string s, ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        cin >> s;
        if (larger(s, ans)){
            x = i; ans = s;
        }
    }
    cout << x << endl << ans;
    return 0;
}
/*
input:
5
98765
12365
87954
1022356
985678

output:
4
1022356
*/