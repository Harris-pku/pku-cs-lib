/*  Coder: Harris
    Time: 2016.11.17
    Website: https://www.luogu.com.cn/problem/P2241
    Algorithm: math
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long x, y; int n, m;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == j) x += (n-i) * (m-j);
            else y += (n-i) * (m-j);
        }
    }
    cout << x << " " << y;
    return 0;
}
/*
input:
2 3

output:
8 10
*/