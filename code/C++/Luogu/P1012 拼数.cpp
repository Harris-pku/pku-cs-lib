/*  Coder: Harris
    Time: 2015.10.24
    Website: https://www.luogu.com.cn/problem/P1116
    Algorithm: string sort
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cmp(string x, string y){
	return x+y > y+x;
}
string s[25]; int n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    sort(s+1, s+n+1, cmp);
    for (int i = 1; i <= n; i++){
        cout << s[i];
    }
    return 0;
}
/*
input:
4
7 13 4 246

output:
7424613
*/