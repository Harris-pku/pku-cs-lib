#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

long long b, p, k, a, c, ans = 1;
int main(){
    cin >> b >> k >> p;
    a = b; c = p;
    while (p){
        if (p&1)
            ans = ans * b % k;
        b = b * b % k;
        p >>= 1;
    }
    cout << a << "^" << c << " mod " << k << "=" << ans % k;
    return 0;
}
