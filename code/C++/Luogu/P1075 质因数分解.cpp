/*  Coder: Harris
    Time: 2015.8.27
    Website: https://www.luogu.com.cn/problem/P1075
    Algorithm: simulation
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int is_prime(int n){
	if (n <= 1) return 0;
	int m = floor(sqrt(n));
	for (int i = 2; i <= m; i++)
	 	if (n%i == 0) return 0;
	return 1;
}

int n, m;
int main(){
    scanf("%d", &n);
    m = floor(sqrt(n));
    for (int i = 2; i <= m; i++){
        if (n%i == 0 && is_prime(i)){
            printf("%d", n/i); break;
        }
    }
    return 0;
}
/*
input:
21

output:
7
*/