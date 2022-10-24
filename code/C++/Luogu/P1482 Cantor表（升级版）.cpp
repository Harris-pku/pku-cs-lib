#include <cstdio>
#include <iostream>

using namespace std;

int a, b, c, d; char e;
int gcd(int a, int b){
    if (!b) return a;
    return gcd(b, a%b);
}
int main(){
    cin >> a >> e >> b >> c >> e >> d;
    cout << b*d / gcd(a*c, b*d) << " " << a*c / gcd(a*c, b*d);
    return 0;
}
