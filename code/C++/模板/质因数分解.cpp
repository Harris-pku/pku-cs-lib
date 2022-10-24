#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int pri[105], top, n;
int main(){
    scanf("%d", &n);
    for (int i = 2; i * i <= n; ++i){
        if (n%i == 0){
            pri[++top] = i;
            while (n%i == 0){
                n /= i;
            }
        }
    }
    if (n != 1) pri[++top] = n;
    for (int i = 1; i <= top; ++i)
        printf("%d\n", pri[i]);
    return 0;
}
