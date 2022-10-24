/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5719
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, k, num1, num2; double sum1, sum2;
int main(){
	scanf("%d%d", &n, &k); 
    for (int i = 1; i <= n; i++){
        if (i % k){
            sum2 += i; num2++;
        }
        else{
            sum1 += i; num1++;
        }
    }
    printf("%.1f %.1f", sum1 / num1, sum2 / num2);
    return 0;
}
/*
input:
100 16

output:
56.0 50.1
*/