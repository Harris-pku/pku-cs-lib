/*  Coder: Harris
    Time: 2020.5.2
    Website: https://www.luogu.com.cn/problem/P5735
    Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath> 
#include <cstring>

using namespace std;

double x[5], y[5];
double dis(int a, int b){ // distance
    double ans = sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
    return ans;
}

int main(){
    for (int i = 1; i <= 3; i++){
        cin >> x[i] >> y[i];
    }
    double ans = dis(1, 2) + dis(2, 3) + dis(3, 1);
    printf("%.2f", ans);
    return 0;
}
/*
input:
0 0 0 3 4 0

output:
12.00
*/