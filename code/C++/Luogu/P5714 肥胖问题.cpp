/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5714
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

double m, h, ans;
int main(){
    cin >> m >> h;
    ans = m / h / h;
    if (ans < 18.5) cout << "Underweight";
    else if (ans < 24) cout << "Normal";
    else cout << ans << endl << "Overweight";
    return 0;
}
/*
input:
70 1.72

output:
Normal
*/