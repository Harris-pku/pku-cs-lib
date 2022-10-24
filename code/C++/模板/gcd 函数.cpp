#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int x, y, ans;
inline int gcd(int a, int b){
    if (!b) return a;
    return gcd(b, a%b);
}
int main(){
	scanf("%d%d", &x, &y);
	printf("%d", gcd(x, y));
}
