#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int catalan[105] = {1, 1}, n;
int main(){
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j < i; ++j){
            catalan[i] = (catalan[i] + catalan[j] * catalan[i-j-1]) % 100;
        }
    printf("%d", catalan[n]);
    return 0;
}
