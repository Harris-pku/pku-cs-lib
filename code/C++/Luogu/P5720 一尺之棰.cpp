/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5720
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int x, t = 1;
int main(){
    scanf("%d", &x);
    while (x > 1){
        x /= 2; t++;
    }
    printf("%d", t);
    return 0;
}
/*
input:
100

output:
7
*/