/*  Coder: Harris
    Time: 2015.9.4
    Website: https://www.luogu.com.cn/problem/P1042
    Algorithm: simulation
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

char s[2505][30], n = 1, t = 1, t2 = 1, len;
int a[100005], b[100005], a2[100005], b2[100005];
bool check(int x){
    len = strlen(s[x]);
    for (int i = 0; i < len; ++i)
        if (s[x][i] == 'E') return 0;
    return 1;
}
int main(){
    cin >> s[1];
    while(check(n)){
        cin >> s[++n];
    }   
    for (int i = 1; i <= n; ++i){
        len = strlen(s[i]);
        for (int j = 0; j < len; ++j){
            if (s[i][j] == 'E'){
                for (i = 1; i <= t; ++i)
                	cout << a[i] << ":" << b[i] << endl;
                cout << endl;
                for (i = 1; i <= t2; ++i)
                	cout << a2[i] << ":" << b2[i] <<endl;
                return 0;
            }
            if (s[i][j] == 'W'){
            	a[t]++; a2[t2]++;
            }
            else if (s[i][j] == 'L'){
            	b[t]++; b2[t2]++;
            }
            if ((a[t]>=11 || b[t]>=11) && abs(a[t]-b[t])>=2)
                t++;
            if ((a2[t2]>=21 || b2[t2]>=21) && abs(a2[t2]-b2[t2])>=2)
                t2++;
        }
    }
    return 0;
}
/*
input:
WWWWWWWWWWWWWWWWWWWW
WWLWE

output:
11:0
11:0
1:1

21:0
2:1
*/