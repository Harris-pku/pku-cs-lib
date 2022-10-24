/*  Coder: Harris
    Time: 2015.7.21
    Website: https://www.luogu.com.cn/problem/P1055
    Algorithm: simulation
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int x, y; char a[15];
int h[15] = {1, 0, 2, 3, 4, 0, 5, 6, 7, 8, 9, 0};
int main(){
    scanf("%s", a);
    for (int i = 0; i <= 10; i++){
        if (a[i] != '-')
            x = (x + (a[i] - '0') * h[i]) % 11;
    }
    if (x == 10 && 'X' == a[12])
        printf("Right");
    else if (x == a[12] - '0')
        printf("Right");
    else{
        if (x == 10)
            a[12] = 'X';
        else
            a[12] = '0' + x;
        printf("%s", a);
    }
    return 0;
}
/*
input:
0-670-82162-4

output:
Right
*/