/*  Coder: Harris
    Time: 2020.7.19
    Website: https://www.luogu.com.cn/problem/P4995
    Algorithm: greedy algorithm
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

long long ans;
int h[305], n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &h[i]);
    }
    sort(h+1, h+n+1);
    int l = 0, r = n;
    while (l < r){
        ans += (h[l]-h[r]) * (h[l]-h[r]); l++;
        ans += (h[l]-h[r]) * (h[l]-h[r]); r--;
    }
    cout << ans;
    return 0;
}
/*
input:
3
6 3 5

output:
49
*/