/*  Coder: Harris
    Time: 2020.2.1
    Website: https://www.luogu.com.cn/problem/P1435
    Description: Given a string, find the min char numbers to insert
                 to make it palindromic
                 给定一个字符串, 求最少插入几个字符使得该字符串成为回文串

    Algorithm: find the size of the LCS of the string and the reverse one,
               the answer is length minus this size
               答案为字符串长度减该串与反串的LCS长度
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[5005][5005], n;
char s1[5005], s2[5005];
int main(){
    scanf("%s", s1+1);
    n = strlen(s1 + 1);
    for (int i = 1; i <= n; i++){
        s2[i] = s1[n-i+1];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%d", n-dp[n][n]);
    return 0;
}
/*
input:
Ab3bd

output:
2
*/