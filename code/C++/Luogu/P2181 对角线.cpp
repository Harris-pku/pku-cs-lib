/*  Coder: Harris
    Time: 2020.3.8
    Website: https://www.luogu.com.cn/problem/P2181
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

unsigned long long n, ans;
int main(){
    cin >> n;
    ans = n * (n-1) / 2 * (n-2) / 3 * (n-3) / 4;
    cout << ans;
    return 0;
}
/*
input:
6

output:
15
*/