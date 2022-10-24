#include <iostream>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, c;
long long gcd(long long x, long long y){
    if (!y) return x;
    return gcd(y, x % y);
}
int main(){
    cin >> a >> b >> c;
    a = a * b / gcd(a, b);
    cout << a * c / gcd(a, c);
    return 0;
}