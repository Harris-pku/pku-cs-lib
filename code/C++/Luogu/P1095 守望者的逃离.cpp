#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[300005], m, s, t;
int main(){
    scanf("%d%d%d", &m, &s, &t);
    for (int i = 1; i <= t; ++i){
        if (m >= 10){
            dp[i] = dp[i-1] + 60; m -= 10;
        }
        else{
            dp[i] = dp[i-1]; m += 4;
        }
    }
    for (int i = 1; i <= t; ++i){
        dp[i] = max(dp[i], dp[i-1] + 17);
        if (dp[i] >= s){
            printf("Yes\n%d", i); return 0;
        }
    }
    printf("No\n%d", dp[t]);
    return 0;
}