#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, m, k, x, t = 10, ans = 1;
int main(){
	scanf("%d%d%d%d", &n, &m, &k, &x);
	while (k > 0){
        if (k&1) ans = (ans*t) % n;
	    k >>= 1; t = (t*t) % n;
	}
	printf("%d", (x+ans*m) % n);
    return 0;
}