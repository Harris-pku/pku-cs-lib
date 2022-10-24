/*  Coder: Harris
    Time: 2020.7.3
    Website: https://www.luogu.com.cn/problem/P5717
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[5];
int main(){
    scanf("%d%d%d", &a[1], &a[2], &a[3]);
    sort(a+1, a+4);
    if (a[1] + a[2] <= a[3]) printf("Not triangle\n");
    else{
        if (a[1]*a[1] + a[2]*a[2] == a[3]*a[3]) printf("Right triangle\n");
        if (a[1]*a[1] + a[2]*a[2]  > a[3]*a[3]) printf("Acute triangle\n");
        if (a[1]*a[1] + a[2]*a[2]  < a[3]*a[3]) printf("Obtuse triangle\n");
        if (a[1] == a[2] || a[2] == a[3]) printf("Isosceles triangle\n");
        if (a[1] == a[3]) printf("Equilateral triangle\n");
    }
    return 0;
}
/*
input:
3 3 3

output:
Acute triangle
Isosceles triangle
Equilateral triangle
*/