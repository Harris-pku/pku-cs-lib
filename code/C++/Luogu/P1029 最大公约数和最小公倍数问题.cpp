#include <cstdio>
#include <iostream>

using namespace std;

int x, y, ans;
inline int gcd(int a, int b){
    if (!b) return a;
    return gcd(b, a%b);
}
int main(){
	scanf("%d%d", &x, &y);
	if (y%x){
		printf("0");return 0;
	}
	y /= x;
	for (int i = 1; i <= y; ++i){
		if (y%i) continue;
	 	if (gcd(i, y/i) == 1) ans++;
	}
	printf("%d", ans);
	return 0;
}
