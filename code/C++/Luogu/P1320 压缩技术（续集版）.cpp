/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P1320
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string s[205]; int n, cur, sum;
int main(){
    cin >> s[0];
    n = s[0].length();
    for (int i = 1; i < n; i++){
        cin >> s[i];
    }
    printf("%d ", n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (s[i][j]-'0' == cur){
                sum++;
            }
            else{
                cur = s[i][j] - '0';
                printf("%d ", sum);
                sum = 1;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
/*
input:
0001000
0001000
0001111
0001000
0001000
0001000
1111111

output:
7 3 1 6 1 6 4 3 1 6 1 6 1 3 7
*/