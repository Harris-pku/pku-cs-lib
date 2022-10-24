/*  Coder: Harris
    Time: 2015.8.29
    Website: https://www.luogu.com.cn/problem/P1200
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char s1[10], s2[10];
int x = 1, y = 1;
int main(){
    scanf("%s", s1);
    scanf("%s", s2);
    for (int i = 0; i < strlen(s1); i++)
        x = (x * (s1[i] - 'A' + 1)) % 47;
    for (int i = 0; i < strlen(s2); i++)
        y = (y * (s2[i] - 'A' + 1)) % 47;
    if (x == y)
        printf("GO");
    else
        printf("STAY");
    return 0;
}
/*
input:
COMETQ
HVNGAT

output:
GO
*/