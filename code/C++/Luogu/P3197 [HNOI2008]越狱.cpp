#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int p = 100003;
long long n, m, ans;
inline long long mi(long long a, long long x){
    long long ansx = 1;
    while (x){
        if (x&1) ansx = ansx * a % p;
        a = a * a % p;
        x >>= 1;
    }
    return ansx;
}
int main(){
    cin >> m >> n;
    ans = mi(m, n) - (m%p) * mi(m-1, n-1) % p;
    cout << (ans + p) % p;
    return 0;
}