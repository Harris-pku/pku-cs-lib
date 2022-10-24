#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int a, n; long long ans = 1;
int main(){
    scanf("%d%d", &a, &n);
    while (n){
        if (n&1) ans *= a;
        a *= a;
        n >>= 1;
    }
    /*for (int i = 0; n >= (1<<i); ++i){
        if ((n>>i)&1) ans *= a;
        a *= a;
    }*/
    cout << ans;
}