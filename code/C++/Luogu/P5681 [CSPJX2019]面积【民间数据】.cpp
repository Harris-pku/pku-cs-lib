/*  Coder: Harris
    Time: 2020.1.31
    Website: https://www.luogu.com.cn/problem/P5681
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

long long a, b, c;
int main(){
    cin >> a >> b >> c;
    if (a*a > b*c) printf("Alice");
    else printf("Bob");
    return 0;
}
/*
input:
5 4 6

output:
Alice
*/