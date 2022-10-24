#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int n, m, t, k = 3;
int main(){
    scanf("%d", &n); m = n;
    while (t < n){
        t = t*2 + k; ++k;
    }
    k--;
    while (t > 0){
        t = (t - k) / 2;
        if (m > t){
            if (m <= t + k){
                if (m == t + 1){
                    printf("m"); break;
                }
                else{
                    printf("o"); break;
                }
            }
            else m = m - (t + k);
        }
        k--;
    }
    return 0;
}