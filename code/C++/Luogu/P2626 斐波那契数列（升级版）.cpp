/*  Coder: Harris
    Time: 2020.2.2
    Website: https://www.luogu.com.cn/problem/P2626
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const long long p = 1 << 31;
long long f[50] = {0, 1, 1}; int n, flag;
int main(){
    scanf("%d", &n);
    for (int i = 3; i <= n; i++){
        f[i] = (f[i-1] + f[i-2]) % p;
    }
    cout << f[n] << "=";
    int m = floor(sqrt(f[n]));
    for (int i = 2; i <= f[n]; i++){
        while (f[n]%i == 0){
            if (!flag){
                printf("%d", i); flag = 1;
            }
            else printf("*%d", i);
            f[n] /= i;
        }
    }
    return 0;
}
/*
input:
6

output:
8=2*2*2
*/