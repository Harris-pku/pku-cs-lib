#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, t;
int main(){
    scanf("%d", &n);
    if (n & 1){
        printf("-1"); return 0;
    }
    for (int i = 30; i > 0; i--){
        if (n >= (1 << i)){
            printf("%d ", (1 << i));
            n -= (1 << i);
        }
    }
    return 0;
}